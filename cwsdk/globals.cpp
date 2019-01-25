#include <Windows.h>
#include "globals.h"
#include "cube_funcs.h"

namespace cube {
	float* gravity = nullptr;
	HWND* hwnd = nullptr;
	bool* input_enabled = nullptr;
	void InitGlobals()
	{
		DWORD trash_protections;
		auto base = cube_funcs::instance()->ImageBase;

		gravity = (float*)(base + 0x2FCD78);
		VirtualProtect((void*)gravity, 4, PAGE_READWRITE, &trash_protections);

		hwnd = (HWND*)(base + 0x36B1C0);

		input_enabled = (bool*)(base + 0x366218);
	}
};