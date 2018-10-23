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

	char World::SetBlock(int x, int y, int z, BlockColor* color_type, Zone* zone) {
		return cube_funcs::instance()->world_setblock(this, x, y, z, color_type, zone);
	}

	BlockColor* World::GetBlock(int x, int y, int z, Zone* zone) {
		return cube_funcs::instance()->world_getblock(this, x, y, z, zone);
	}
};