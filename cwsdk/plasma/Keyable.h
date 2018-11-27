#pragma once

#include <cstdint>
#include "NamedObject.h"

namespace plasma {
	class Keyable : NamedObject {
	public:
		//void* vtable;
		uint32_t field_20;
		uint32_t field_24;
		uint8_t field_28;
		uint8_t field_29;
		uint8_t field_2A;
		uint8_t field_2B;
		uint16_t field_2C;
		uint8_t field_2E;
		uint8_t field_2F;
		uint32_t field_30;
		uint32_t field_34;
		uint32_t field_38;
		uint32_t field_3C;
		uint32_t field_40;

		virtual void vf_dtor(uint8_t x) {};
	};
};