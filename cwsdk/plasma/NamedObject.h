#pragma once

#include "../msvc_bincompat.h"
#include "Object.h"

namespace plasma {
	class NamedObject : Object {
	public:
		//void* vtable;
		MSVCBinCompat::wstring name;

		virtual void vf_dtor(uint8_t x) {};
	};
};
