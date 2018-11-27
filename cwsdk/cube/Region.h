#pragma once

#include <cstdint>

namespace cube {
	struct Zone;

	struct Region
	{
		int vftable;
		int field_4;
		char field_8;
		int field_C;
		int field_10;
		int field_14;

		struct Region_SubField1{
			int field_0;
			int field_4;
			int field_8;
			char field_C;
			char field_D;
			char field_E;
			char field_F;
		} unk_subfields_1[4096];
		
		Zone *zones[4096];

		struct Region_SubField2
		{
			int field_0;
			int field_4;
			int field_8;
			int field_C;
			int field_10;
			int field_14;
			int field_18;
			int field_1C;
			int field_20;
			int field_24;
			int field_28;
			int field_2C;
			int field_30;
			int field_34;
			int field_38;
			int field_3C;
			uint16_t field_40;
			int field_44;
			int field_48;
			int field_4C;
			int field_50;
			int field_54;
			int field_58;
			uint8_t field_5C;
			int field_60;
			int field_64;
		} unk_subfields_2[64];

		char field_15A18;
		int field_15A1C;
		int field_15A20;
		int field_15A24;
	};
};