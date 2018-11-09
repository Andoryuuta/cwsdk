#pragma once

#include "memory_management.h"

#include "./cube/GameController.h"
#include "./cube/ChatWidget.h"
#include "./cube/Chunk.h"
#include "./cube/Creature.h"
#include "./cube/Field.h"
#include "./cube/GameController.h"
#include "./cube/Region.h"
#include "./cube/World.h"
#include "./cube/Zone.h"
#include "./cube/Speech.h"

#include "cube_util.h"

namespace cube {
	GameController* GetGameController();
	void InitAPI();
}