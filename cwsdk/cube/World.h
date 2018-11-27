#pragma once

#include <Windows.h>

#include "../msvc_bincompat.h"
#include "../non_cube.h"
#include "Speech.h"

namespace cube {
	struct Creature;
	struct Region;
	struct Zone;
	struct Sprite;

	struct World
	{
		int vftable;
		MSVCBinCompat::map<uint64_t, Creature*>* EntitesMap;
		int field_8;
		MSVCBinCompat::map<uint64_t, void*>* AirshipMap;
		int field_10;
		int field_14;
		int field_18;
		int sprite_manager_instance_start_vtable;
		MSVCBinCompat::vector<Sprite*> cub_sprite_models; // 0x20
		int field_2C;
		Speech speech;
		int field_88;
		int field_8C;
		int field_90;
		MSVCBinCompat::string world_name;
		int field_AC;
		int field_B0;
		int field_B4;
		Creature *local_player;
		Region *main_regions[1024][1024];
		Region *unk_regions[1024][1024];
		int field_8000BC;
		_RTL_CRITICAL_SECTION critical_section; // Used for all generic World locking. (0x8000C0)
		_RTL_CRITICAL_SECTION block_op_critical_section; // Used for all block operations (region, zone, field, addition/change/deletion) in conjunction with the previous lock. (0x8000D8)
		int field_8000F0;
		int field_8000F4;
		int field_8000F8;
		int field_8000FC;
		int field_800100;
		MSVCBinCompat::map<uint32_t, MSVCBinCompat::wstring>* EntityNames;
		int field_800108;
		MSVCBinCompat::map<uint32_t, MSVCBinCompat::wstring>* PlaceableObjectNames;
		int field_800110;
		MSVCBinCompat::map<uint32_t, MSVCBinCompat::wstring>* SkillNames;
		int field_800118;
		MSVCBinCompat::map<uint32_t, MSVCBinCompat::wstring>* AbilityNames;
		int field_800120;
		MSVCBinCompat::map<Category, MSVCBinCompat::wstring>* PlaceNames;
		int field_800128;
		MSVCBinCompat::map<Category, MSVCBinCompat::wstring>* CityQuarterNames;
		int field_800130;
		MSVCBinCompat::map<Category, MSVCBinCompat::wstring>* ItemNames;
		int field_800138;
		MSVCBinCompat::map<MSVCBinCompat::wstring, uint32_t>* Inverse_EntityNames_Map;
		int field_800140;
		MSVCBinCompat::map<MSVCBinCompat::wstring, uint32_t>* Inverse_PlaceableObjectNames_Map;
		int field_800148;
		MSVCBinCompat::map<MSVCBinCompat::wstring, uint32_t>* Inverse_ItemNames_Map;
		int field_800150;
		int UnkMap; // map<uint32_t, cube::Sprite*>*
		int field_800158;
		int Time;
		int field_800160;
		int field_800164;
		int other_stuff;
		int field_80016C;
		int field_800170;
		int field_800174;
		int field_800178;
		int field_80017C;
		int field_800180;
		int field_800184;
		int field_800188;
		int field_80018C;
		int field_800190;
		int field_800194;
		int field_800198;
		int field_80019C;
		int field_8001A0;
		int field_8001A4;
		int field_8001A8;
		int field_8001AC;
		int field_8001B0;
		int field_8001B4;
		int field_8001B8;
		int field_8001BC;
		int field_8001C0;
		int field_8001C4;
		int field_8001C8;
		int field_8001CC;
		int field_8001D0;
		int field_8001D4;
		int field_8001D8;
		int field_8001DC;
		int field_8001E0;
		int field_8001E4;
		int field_8001E8;
		int field_8001EC;
		int field_8001F0;
		int field_8001F4;
		int field_8001F8;
		int field_8001FC;
		int field_800200;
		int field_800204;
		int field_800208;
		int field_80020C;
		int field_800210;
		int field_800214;
		int field_800218;
		int field_80021C;
		int field_800220;
		int field_800224;
		int field_800228;
		int field_80022C;
		int field_800230;
		int field_800234;
		int field_800238;
		int field_80023C;
		int field_800240;
		int field_800244;
		int field_800248;
		int field_80024C;
		int field_800250;
		int field_800254;
		int field_800258;
		int field_80025C;
		int field_800260;
		int field_800264;
		int field_800268;
		int field_80026C;
		int field_800270;
		int field_800274;
		int field_800278;
		int field_80027C;
		int field_800280;
		int field_800284;
		int field_800288;
		int field_80028C;
		int field_800290;
		int field_800294;
		int field_800298;

		void Lock();
		void Unlock();
		Zone* GetZone(int zone_x, int zone_y);
		char SetBlock(int x, int y, int z, BlockColor* color_type, Zone* zone);
		BlockColor* GetBlock(int x, int y, int z, Zone* zone);

		// Essentially Copy+Pasted from ChrisMiuchiz
		bool VoxelRayCast(Vector3<int64_t> origin, Vector3<double> direction, int64_t max_distance_in_blocks, Vector3<int64_t>* out_block, Vector3<int64_t>* out_face);
	};
};