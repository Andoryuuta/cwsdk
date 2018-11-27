#pragma once

#include <cstdint>
#include "../msvc_bincompat.h"

namespace plasma {
	class Attribute {
	public:
		uint32_t vec_ptr;
		uint32_t field_4;
		uint32_t field_8;
		uint32_t field_C;
		uint32_t field_10;
		uint32_t field_14;
		uint32_t field_18;
		uint32_t current_frame;
		MSVCBinCompat::string attribute_name;
		uint32_t field_38;
		uint32_t field_3C;
		uint32_t field_40;
		uint32_t field_44;
	};
};