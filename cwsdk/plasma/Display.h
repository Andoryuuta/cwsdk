#pragma once

#include <cstdint>
#include "Keyable.h"
#include "DiscreteAttribute.h"
#include "ContinuousAttribute.h"
#include "Vector.h"

namespace plasma {
	class Display : Keyable {
		DiscreteAttribute<uint32_t> visibility;
		DiscreteAttribute<uint32_t> clipping;
		ContinuousAttribute<Vector<4, float>> fill;
		ContinuousAttribute<Vector<4, float>> stroke;
		ContinuousAttribute<float> blurRadius;
		uint32_t field_1FC;
		uint32_t field_200;
		uint32_t field_204;
		uint32_t field_208;

		virtual void vf_dtor(uint8_t x) {};
	};
};