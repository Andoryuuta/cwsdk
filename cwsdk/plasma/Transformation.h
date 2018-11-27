#pragma once

#include <cstdint>
#include "Keyable.h"
#include "ContinuousAttribute.h"
#include "Vector.h"
#include "Matrix.h"

namespace plasma {
	class Transformation : Keyable {
	public:
		ContinuousAttribute<Vector<2, float>> translation;
		ContinuousAttribute<Matrix<float>> deformation;
		ContinuousAttribute<Vector<3, float>> rotation;
		ContinuousAttribute<Vector<2, float>> pivot;
		uint32_t field_1A4;
		uint32_t field_1A8;
		Matrix<float> some_matrix_1;
		Matrix<float> some_matrix_2;
		uint32_t field_22C;

		virtual void vf_dtor(uint8_t x) {};
	};
};