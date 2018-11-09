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
	typedef void(__thiscall* vec3_int64_fom_vec3_float_t)(Vector3<int64_t>*, Vector3<float>*);
	typedef cube::Zone*(__thiscall* world_getzone_t)(cube::World*, int zone_x, int zone_y);
	typedef BlockColor*(__thiscall* world_getblock_t)(cube::World*, int x, int y, int z, cube::Zone*);
	typedef char(__thiscall* world_setblock_t)(cube::World*, int x, int y, int z, BlockColor*, cube::Zone*);
	typedef MSVCBinCompat::wstring*(__thiscall *speech_get_localization_from_dict_t)(cube::Speech*, MSVCBinCompat::wstring* out, MSVCBinCompat::wstring* key, MSVCBinCompat::wstring word_form);
	typedef MSVCBinCompat::wstring*(__stdcall *generate_rare_creature_name_t)(MSVCBinCompat::wstring*, uint32_t GUID_low, uint32_t race);

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
		world_getzone_t world_getzone;
		world_getblock_t world_getblock;
		world_setblock_t world_setblock;
		speech_get_localization_from_dict_t speech_get_localization_from_dict;
		generate_rare_creature_name_t generate_rare_creature_name;
};

