#pragma once

#include <cstdint>

namespace cube {
	struct Chunk
	{
		int vftable;
		int field_4;
		int linked_list_ChunkBuffers;
		int linked_list_ChunkBuffers_count;
		int linked_list_unk;
		int linked_list_unk_count;
		int X;
		int Y;
		int field_20;
		int field_24;
		int field_28;
		int field_2C;
		int field_30;
		int field_34;
		int field_38;
		int field_3C;
		int field_40;
		int field_44;
		int field_48;
		int field_4C;
		int field_50;
		int field_54;
		int field_58;
		int field_5C;
		int field_60;
		int field_64;
		int field_68;
		int field_6C;
		int field_70;
		uint8_t needs_update;
		__declspec(align(4)) char unk_buffer[448];
		int field_238;
		int field_23C;
		int field_240;
		int field_244;
		int field_248;
		int field_24C;
		int critical_section_and_spin_count;
		int field_254;
		int field_258;
		int field_25C;
		int field_260;
		int field_264;
	};
};