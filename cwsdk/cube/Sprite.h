#pragma once

#include <cstdint>
#include <string>
#include "../msvc_bincompat.h"
#include "../dx9_stub.h"

namespace cube {
	struct Database;

	struct Sprite
	{
		uint32_t field_0;
		uint32_t field_4;
		uint32_t field_8;
		uint32_t field_C;
		uint32_t field_10;
		uint32_t field_14;
		uint32_t field_18;
		uint32_t field_1C;
		uint32_t field_20;
		uint32_t field_24;
		uint32_t field_28;
		uint32_t field_2C;
		uint32_t data_ptr;
		uint32_t VertexBuffer;
		uint32_t IndexBuffer;
		uint32_t DIP_NumVertices;
		uint32_t DIP_PrimativeCount;
		uint32_t model_x_size;
		uint32_t model_y_size;
		uint32_t model_z_size;
		uint32_t field_50;
		uint8_t field_54;
		uint8_t field_55;
		uint8_t field_56;
		uint8_t field_57;
		LPDIRECT3DDEVICE9 Direct3DDevice9;
		uint16_t field_5C;
		uint8_t field_5E;
		uint8_t field_5F;

		Sprite(LPDIRECT3DDEVICE9 device, uint32_t unk_set_0 = 0);
		void LoadFromCubFile(std::string filename, cube::Database* db = nullptr, uint32_t unk_set_1 = 1);
	};
};
