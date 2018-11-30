#include "Sprite.h"
#include <Windows.h>

namespace cube {
	Sprite::Sprite(LPDIRECT3DDEVICE9 device, uint32_t unk_set_0) {
		auto imageBase = (uint32_t)GetModuleHandleA(NULL);
		typedef void(__thiscall* sprite_ctor_t)(cube::Sprite*, LPDIRECT3DDEVICE9, uint32_t);
		auto sprite_ctor = (sprite_ctor_t)(imageBase + 0xE6A20);

		sprite_ctor(this, device, unk_set_0);
	}

	void Sprite::LoadFromCubFile(std::string filename, cube::Database* db, uint32_t unk_set_1) {
		auto imageBase = (uint32_t)GetModuleHandleA(NULL);
		typedef void(__thiscall* sprite_load_from_cub_file_t)(cube::Sprite*, MSVCBinCompat::string*, cube::Database*, uint32_t);
		auto sprite_load_from_cub_file = (sprite_load_from_cub_file_t)(imageBase + 0xE7290);

		auto bincompat_filename = MSVCBinCompat::string(filename);
		sprite_load_from_cub_file(this, &bincompat_filename, db, unk_set_1);
	}
};