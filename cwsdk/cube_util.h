#pragma once

#include "cube.h"

namespace cube {
	namespace util {

		cube::Creature* SpawnCreature(Vector3<int64_t> position, cube::Creature::Race race, uint32_t hostility_flags, uint32_t level, uint64_t owner_guid);
		cube::Creature* SpawnMonster(Vector3<int64_t> position, cube::Creature::Race race, uint32_t hostility_flags, uint32_t level);
	};
};