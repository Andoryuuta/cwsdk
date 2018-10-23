#include <windows.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdint>
#include <sstream>
#include <vector>

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

void print_pos() {
	auto gc = cube::GetGameController();
	gc->ChatWidget->Print(L"X: ", Color::Green());
	gc->ChatWidget->Print(std::to_wstring(gc->local_player->position.X) + L"\n", Color::White());
	gc->ChatWidget->Print(L"Y: ", Color::Green());
	gc->ChatWidget->Print(std::to_wstring(gc->local_player->position.Y) + L"\n", Color::White());
	gc->ChatWidget->Print(L"Z: ", Color::Green());
	gc->ChatWidget->Print(std::to_wstring(gc->local_player->position.Z) + L"\n", Color::White());
}


DWORD WINAPI MyFunc(LPVOID lpvParam) {
	OpenConsole();
	cube::InitGlobals();
	auto gc = cube::GetGameController();

	while(true){
		try
		{
			// Key H down
			if (GetAsyncKeyState(0x48) & 0x8000) {

				// Get the looking-at block offset by using some incomprehensible function
				// to convert from the vec3 float camera offset to vec3 int64 position offset.
				Vector3<int64_t> looking_at_offset = Vector3<int64_t>();
				looking_at_offset.LoadFromVector3_float(&gc->local_player->camera_offset); 

				Vector3<int64_t> pos = gc->local_player->position;

				Vector3<int64_t> block_pos;
				block_pos.X = (looking_at_offset.X + pos.X);
				block_pos.Y = (looking_at_offset.Y + pos.Y);
				block_pos.Z = (looking_at_offset.Z + pos.Z);

				/*
				std::cout << "\nHIX: " << block_pos.X << std::endl;
				std::cout << "Y: " << block_pos.Y << std::endl;
				std::cout << "Z: " << block_pos.Z << std::endl;
				*/

				// Get block at position
				//auto block = gc->world.GetBlock(v->X, v->Y, v->Z, (cube::Zone*)nullptr);
				//std::cout << "R:" << (uint32_t)block->Red << ", G:" << (uint32_t)block->Green << ", B:" << (uint32_t)block->Blue << ", type:" << (uint32_t)block->Type << std::endl;
				gc->world.Lock();


				BlockColor color = BlockColor(0, 255, 125, 1);
				gc->world.SetBlock(block_pos.X / 0x10000, block_pos.Y / 0x10000, block_pos.Z / 0x10000, &color, (cube::Zone*)nullptr);
				gc->UpdateChunk(block_pos.X / 0x200000, block_pos.Y / 0x200000);

				gc->world.Unlock();

				Sleep(200);
			}
			
			// J key
			if (GetAsyncKeyState(0x4A) & 0x8000) {
				break;
			}

		}
		catch (const std::exception&)
		{
			std::cout << "Got exception!" << std::endl;
		}
		Sleep(20);
	}


	/*
	std::cout << *cube::gravity << std::endl;
	auto real_grav = *cube::gravity;
	*cube::gravity = 1.0f;
	Sleep(30 * 1000);
	*cube::gravity = real_grav;
	*/




	//print_pos();

	/*
	auto gc = cube::GetGameController();
	while(true) {

		// Wait until user is typing to send message and break.
		if (gc->ChatWidget->is_typing_message) {
			gc->ChatWidget->Print(L"ChrisMiuchiz", Color::Green());
			gc->ChatWidget->Print(L" : hi. I've noticed that you're typing.\n", Color::White());
			break;
		}

		Sleep(5000);
	}
	*/



	std::cout << "Done!" << std::endl;
	//getchar();
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


