#pragma once

#include "assert_size.h"

#include "./cube/GameController.h"
#include "./cube/ChatWidget.h"
#include "./cube/Chunk.h"
#include "./cube/Creature.h"
#include "./cube/Database.h"
#include "./cube/Field.h"
#include "./cube/Region.h"
#include "./cube/Speech.h"
#include "./cube/SpriteManager.h"
#include "./cube/Sprite.h"
#include "./cube/World.h"
#include "./cube/WorldMap.h"
#include "./cube/Zone.h"

assert_size(cube::GameController, 0x1001018)
assert_size(cube::ChatWidget, 0x190) // Should this be in plasma.h?
assert_size(cube::Chunk, 0x268)
assert_size(cube::Creature, 0x1E60)
assert_size(cube::Database, 0x8)
assert_size(cube::Field, 0x20)
assert_size(cube::Region, 0x15A28)
assert_size(cube::Speech, 0x58)
assert_size(cube::Sprite, 0x60)
assert_size(cube::SpriteManager, 0x14)
assert_size(cube::World, 0x80029C) // Only instanced once, may be incorrect.
assert_size(cube::WorldMap, 0x800108) // Only instanced once, may be incorrect.
assert_size(cube::Zone, 0xc8)


#include "cube_util.h"

namespace cube {
	GameController* BusywaitForGameController();
	GameController* GetGameController();
	void InitAPI();
}