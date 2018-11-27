#pragma once

#include "../msvc_bincompat.h"
#include "Attribute.h"

namespace plasma {
	template<typename T>
	class ContinuousAttribute {
	public:
		Attribute base;
		MSVCBinCompat::vector<T> data;

		virtual void vf_dtor(uint8_t x) {};
	};
};