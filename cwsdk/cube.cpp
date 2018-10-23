#include "cube.h"

#include <iostream>
#include <Windows.h>
#include "msvc_bincompat.h"
#include "cube_funcs.h"

#include "./cube/ChatWidget.h"
#include "./cube/Chunk.h"
#include "./cube/Creature.h"
#include "./cube/Field.h"
#include "./cube/GameController.h"
#include "./cube/Region.h"
#include "./cube/World.h"
#include "./cube/Zone.h"

namespace cube {
	GameController* GetGameController() {
		auto imageBase = (uint32_t)GetModuleHandleA(NULL);
		GameController* gc = *(GameController**)(imageBase + 0x36B1C8);
		return gc;
	}
};