#pragma once

#include <Windows.h>
#include <cstdint>
#include "../msvc_bincompat.h"
#include "../Matrix4x4.h"
#include "Database.h"

namespace cube {
	struct CubeShader;
	struct World;
	struct ZoneTile;
	struct Sprite;

	struct WorldMap
	{
		uint32_t vtable;
		Matrix4x4 some_plasma_label_matrix; // Effects the plasma text labels on the world map.
		Matrix4x4 some_map_sprite_matrix; // Effects the sprites drawn on the world map.

		// offset/position from panning around map with middle mouse button.
		float cam_offset_x;
		float cam_offset_y;

		uint32_t field_8C;
		uint32_t field_90;
		uint32_t field_94;
		uint32_t field_98;
		uint32_t field_9C;
		uint8_t field_A0;
		void* Direct3DDevice9;
		cube::CubeShader *shader;
		cube::World *world;
		cube::ZoneTile *ZoneTiles[1024][1024];
		uint8_t unk_buf_2[4194304]; // Probably: void* buf[1024][1024];
		cube::Sprite *biome_edge_marker_sprite;
		cube::Sprite *sprite_skull_cub; // "skull.cub" sprite
		uint32_t timer_for_sprite_animation;
		uint32_t field_8000BC;
		_RTL_CRITICAL_SECTION critical_section_1;
		_RTL_CRITICAL_SECTION critical_section_2;
		Database db;
		uint32_t unk_set_to_1;
		MSVCBinCompat::vector<Sprite*> unused_legacy_map_tiles; // Legacy map tiles. Still loaded, but unused.
	};

};