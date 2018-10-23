#include <Windows.h>
#include "globals.h"
#include "cube_funcs.h"

namespace cube {
	float* gravity = nullptr;
	void InitGlobals()
	{
		auto base = cube_funcs::instance()->ImageBase;

		gravity = (float*)(base + 0x2FCD78);
		DWORD trash_protections;
		VirtualProtect((void*)gravity, 4, PAGE_READWRITE, &trash_protections);

	}
};