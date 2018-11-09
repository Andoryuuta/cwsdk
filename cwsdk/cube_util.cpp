#include "cube_util.h"
#include <Windows.h>

namespace cube {
	namespace util {
		cube::Creature* SpawnMonster(Vector3<int64_t> position, cube::Creature::Race race, uint32_t hostility_flags, uint32_t level) {
			auto imageBase = (uint32_t)GetModuleHandleA(NULL);
			auto gc = cube::GetGameController();

			// ctor
			typedef cube::Creature* (__thiscall* cube_creature_ctor_t)(cube::Creature*, uint64_t*);
			auto cube_creature_ctor = (cube_creature_ctor_t)(imageBase + 0x3B690);

			// entity map insert
			typedef cube::Creature** (__thiscall* std_map_guid_creature_get_insert_node_t)(void*, uint64_t*);
			auto std_map_guid_creature_get_insert_node = (std_map_guid_creature_get_insert_node_t)(imageBase + 0x68AD0);

			// init graphics
			typedef int(__cdecl* init_creature_graphics_by_race_t)(uint32_t* race, void* appearance_substruct, uint32_t);
			auto init_creature_graphics_by_race = (init_creature_graphics_by_race_t)(imageBase + 0x3F7C0);

			// Init companion behaviors
			typedef int(__thiscall* cube_world_init_companion_t)(cube::World* world, uint64_t guid, cube::Creature* c);
			auto cube_world_init_companion = (cube_world_init_companion_t)(imageBase + 0x1EE7A0);

			// Lock the world
			gc->world.Lock();

			// Haven't figured out real GUID generation yet, just make a counter.
			static uint64_t guid = 0xCAFECAFE00000000;
			guid++;
			std::cout << "GUID:" << guid << std::endl;

			// Make sure its on heap because we're giving away a pointer to it.
			cube::Creature* creature = new cube::Creature();

			// Ctor
			cube_creature_ctor(creature, &guid);

			// Insert a pointer into the map
			*std_map_guid_creature_get_insert_node(&gc->world.EntitesMap, &guid) = creature;

			// Setup the location and race
			creature->position = position;
			creature->race = (uint32_t)race;
			creature->hostility_flags = hostility_flags;
			//creature->parent_owner = 1;
			creature->level = level;

			// Call the graphical setup function that gets the proper models and offsets for the given race.
			init_creature_graphics_by_race(&creature->race, &creature->appearance_struct_field_0, 0);

			// Init some basic behaviors as a "pet", but set the owner GUID to 0 so that is doesn't have an owner and attacks anyone.
			// Don't know if this is a good way to do this, but it works for getting the spoopy mod released tonight.
			cube_world_init_companion(&gc->world, 0, creature);

			// Okay, I'm done, you can have this back if you want.....
			gc->world.Unlock();

			return creature;
		}
	};
};