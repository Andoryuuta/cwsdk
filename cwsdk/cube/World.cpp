#include <Windows.h>
#include "World.h"
#include "../cube_funcs.h"

namespace cube {
	void World::Lock() {
		EnterCriticalSection((LPCRITICAL_SECTION)&this->critical_section);
	}

	void World::Unlock() {
		LeaveCriticalSection((LPCRITICAL_SECTION)&this->critical_section);
	}

	Zone* World::GetZone(int zone_x, int zone_y) {
		return cube_funcs::instance()->world_getzone(this, zone_x, zone_y);
	}

	char World::SetBlock(int x, int y, int z, BlockColor* color_type, Zone* zone) {
		return cube_funcs::instance()->world_setblock(this, x, y, z, color_type, zone);
	}

	BlockColor* World::GetBlock(int x, int y, int z, Zone* zone) {
		return cube_funcs::instance()->world_getblock(this, x, y, z, zone);
	}

	// Essentially Copy+Pasted from ChrisMiuchiz
	bool World::VoxelRayCast(Vector3<int64_t> origin, Vector3<double> direction, int64_t max_distance_in_blocks, Vector3<int64_t>* out_block, Vector3<int64_t>* out_face) {
		Vector3<int64_t> block_pos = Vector3<int64_t>(origin.X / 0x10000, origin.Y / 0x10000, origin.Z / 0x10000);
		Vector3<int64_t> last_block_pos = block_pos;

		double reach_limit = 65536.0 * max_distance_in_blocks;
		double raycast_precision = 1000.0;
		bool within_reach = false;
		for (double world_units_traveled = 0.0; world_units_traveled <= reach_limit; world_units_traveled += raycast_precision) {
			last_block_pos = block_pos;

			block_pos.X = origin.X / 0x10000;
			block_pos.Y = origin.Y / 0x10000;
			block_pos.Z = origin.Z / 0x10000;

			BlockColor* color = this->GetBlock((int)block_pos.X, (int)block_pos.Y, (int)block_pos.Z, (cube::Zone*)nullptr);
			if (color->Type != 0) {
				*out_block = block_pos;
				*out_face = last_block_pos;
				within_reach = true;
				break;
			}

			origin.X -= (int64_t)(direction.X * raycast_precision);
			origin.Y -= (int64_t)(direction.Y * raycast_precision);
			origin.Z -= (int64_t)(direction.Z * raycast_precision);
		}

		return within_reach;
	}
};