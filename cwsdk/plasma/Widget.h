#pragma once

#include <cstdint>
#include "NamedObject.h"
#include "Matrix.h"

namespace plasma {
	class Node;

	class Widget : NamedObject {
	public:
		uint32_t field_20;
		float field_24;
		uint32_t field_28;
		uint32_t field_2C;
		uint32_t field_30;
		uint32_t field_34;
		uint32_t plasma_D3D9RenderSurface;
		uint32_t x_offset;
		uint32_t y_offset;
		uint32_t field_44;
		uint32_t field_48;
		float field_4C;
		float field_50;
		uint32_t field_54;
		uint32_t field_58;
		float field_5C;
		float field_60;
		uint32_t field_64;
		uint32_t field_68;
		float width;
		float height;
		uint32_t field_74;
		uint32_t field_78;
		uint16_t field_7C;
		uint32_t field_80;
		uint32_t field_84;
		uint32_t field_88;
		uint32_t field_8C;
		uint32_t field_90;
		uint32_t field_94;
		uint32_t field_98;
		uint32_t field_9C;
		uint32_t field_A0;
		Matrix<float> some_matrix_1;
		Matrix<float> some_matrix_2;
		uint32_t flags;
		uint32_t field_128;
		uint32_t field_12C;
		uint8_t field_130;
		uint32_t field_134;
		uint32_t field_138;
		uint32_t field_13C;
		uint32_t field_140;
		Node *node;
		uint32_t field_148;
		uint32_t field_14C;
		uint32_t field_150;
		uint32_t field_154;
		uint32_t field_158;
	};
};