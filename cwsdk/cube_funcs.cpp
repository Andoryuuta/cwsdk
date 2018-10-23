#include "cube_funcs.h"
#include <Windows.h>
#include <iostream>

// Singleton pattern methods.
cube_funcs* cube_funcs::_instance = nullptr;
cube_funcs* cube_funcs::instance() {
	if (_instance == nullptr) {
		_instance = new cube_funcs();
	}
	return _instance;
}

cube_funcs::cube_funcs() {
	ImageBase = (uint32_t)GetModuleHandleA(NULL);
	chatwidget_print = (chatwidget_print_t)(ImageBase + 0x3AB30);
	vec3_int64_fom_vec3_float = (vec3_int64_fom_vec3_float_t)(ImageBase + 0x2C460);
	world_getblock = (world_getblock_t)(ImageBase + 0x2F7E0);
	world_setblock = (world_setblock_t)(ImageBase + 0x4E7A0);
}