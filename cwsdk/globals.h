#pragma once
#include <Windows.h>

namespace cube {
	void InitGlobals();
	extern float* gravity;
	extern HWND* hwnd;
	extern bool* input_enabled;
};
