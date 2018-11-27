#include <windows.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdint>
#include <sstream>
#include <vector>
#include <bitset>
#include <map>

#include "cwsdk.h"


// Open new console for c(in/out/err)
void OpenConsole()
{
	AllocConsole();
	FILE* cinStream;
	FILE* coutStream;
	FILE* cerrStream;
	freopen_s(&cinStream, "CONIN$", "r", stdin);
	freopen_s(&coutStream, "CONOUT$", "w", stdout);
	freopen_s(&cerrStream, "CONOUT$", "w", stderr);
}

// Prints the world map of `cube::Creature`s.
void print_entities() {

	auto gc = cube::GetGameController();
	auto stdMap = gc->world.EntitesMap->CopyToSTDMap();

	for (auto const& x : stdMap)
	{
		auto key = x.first;
		auto val = x.second;

		std::cout << "cube::Creature addr: " << std::hex << val << std::endl;
		std::wcout << L"\tName: " << val->GetName() << std::endl;
		std::cout << "\tGUID: " << std::dec << val->GUID << std::endl;
		std::cout << "\tShown on map / Objective boss:" << (val->entity_data.appearance.movement_flags & 0x2000) << std::endl;
		std::cout << "\thostility_flags: " << std::hex << std::bitset<32>(val->entity_data.hostility_flags) << std::endl;
		std::cout << "\tmovement_flags: " << std::hex << std::bitset<32>(val->entity_data.appearance.movement_flags) << std::endl;

		if (key != gc->local_player->GUID) {
			//val->parent_owner = gc->local_player->GUID;
			std::cout << "\tdistance in blocks:" << std::dec << gc->local_player->DistanceFrom(val) / 65536 << std::endl;
			//val->hostility_flags = 0x0;
		}
	}
}


void add_petfood() {
	auto gc = cube::GetGameController();



	// Get our current zone.
	int zone_x = (gc->local_player->entity_data.position.X / 65536) / 256;
	int zone_y = (gc->local_player->entity_data.position.Y / 65536) / 256;
	cube::Zone* cur_zone = gc->world.GetZone(zone_x, zone_y);

	gc->world.Lock();
	for (int i = 0; i <= 155; i++) {
		// make the pickupable_object and use the game's default constructor for init values.
		zone_pickupable_object obj;

		// Make the petfood item(s)
		obj.item.category_id = 20;
		obj.item.item_id = i;

		obj.position = gc->local_player->entity_data.position;
		obj.position.X += (i - 5) * 65536; // offset by 5 blocks every iteration

		// append the object to the zones objects vector.
		cur_zone->pickupable_objects.push_back(obj);
	}
	gc->world.Unlock();
}

DWORD WINAPI MyFunc(LPVOID lpvParam) {
	OpenConsole();
	cube::InitGlobals();
	auto gc = cube::GetGameController();
	print_entities();

	try
	{
		while (true) {
			if (GetAsyncKeyState((int)'H') & 0x8000) {
				cube::Creature* creature = cube::util::SpawnMonster(gc->local_player->entity_data.position, cube::Creature::Race::Cow, 1, gc->local_player->entity_data.level);
				gc->ChatWidget->Print(L"Spawned ", Color::White());
				gc->ChatWidget->Print(creature->GetName(), Color::Green());
				gc->ChatWidget->Print(L"\n", Color::White());
				Sleep(250);
			}

			if (GetAsyncKeyState((int)'N') & 0x8000) {
				add_petfood();
				gc->ChatWidget->Print(L"Spawned petfood objects.\n", Color::White());
				Sleep(1000);
			}

			if (GetAsyncKeyState((int)'J') & 0x8000) {
				gc->ChatWidget->Print(L"Ending cwsdk test.\n", Color::Blue());
				std::cout << "Exit!" << std::endl;
				break;
			}
		}

		Sleep(20);
	}
	catch (const std::exception&)
	{
		std::cout << "got exception" << std::endl;
	}

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, 0, MyFunc, 0, 0, NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


