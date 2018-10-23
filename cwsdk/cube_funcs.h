#pragma once
#include <cstdint>
#include "msvc_bincompat.h"
#include "Vector3.h"
#include "Cube.h"


// This class is a singleton that holds all of the function-pointers and their typedefs, auto-image-rebased on init
class cube_funcs
{
	// Typedefs.
	typedef void(__thiscall* chatwidget_print_t)(uint32_t, MSVCBinCompat::wstring*, Color*);
	//typedef void(__thiscall* vec3_int64_fom_vec3_float_t)(Vector3<int64_t>*, Vector3<float>*);
	typedef void(__thiscall* vec3_int64_fom_vec3_float_t)(Vector3<int64_t>*, Vector3<float>*);
	typedef BlockColor*(__thiscall* world_getblock_t)(cube::World*, int, int, int, cube::Zone*);
	typedef char(__thiscall* world_setblock_t)(cube::World*, int, int, int, BlockColor*, cube::Zone*);

	// Singleton pattern start
	public:
		static cube_funcs* instance();

	public:
		cube_funcs(cube_funcs const&) = delete;
		void operator=(cube_funcs const&) = delete;
	
	private:
		static cube_funcs* _instance;
		cube_funcs();
	// Singleton pattern end

	public:
		uint32_t ImageBase;
		chatwidget_print_t chatwidget_print;
		vec3_int64_fom_vec3_float_t vec3_int64_fom_vec3_float;
		world_getblock_t world_getblock;
		world_setblock_t world_setblock;
};

