#pragma once

namespace plasma {
	template<typename T>
	class ContinuousArrayAttribute {
	public:
		Attribute base;
		MSVCBinCompat::vector<T> data;

		virtual void vf_dtor(uint8_t x) {};
	};
};