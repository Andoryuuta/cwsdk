#pragma once

#include <cstdint>
#include "../msvc_bincompat.h"
#include "Shape.h"
#include "ContinuousArrayAttribute.h"
#include "ContinuousAttribute.h"
#include "DiscreteAttribute.h"

namespace plasma {
	class MeshShape : Shape {
	public:
		ContinuousArrayAttribute<Vector<2, float>> positions;
		ContinuousArrayAttribute<Vector<2, float>> textCoords;
		ContinuousArrayAttribute<Vector<4, float>> colors;
		ContinuousArrayAttribute<Vector<4, float>> strokeColors;
		ContinuousArrayAttribute<Vector<4, float>> extrusionBackColors;
		ContinuousArrayAttribute<Vector<4, float>> extrusionFrontColors;
		ContinuousArrayAttribute<float> strokeWidths;
		MSVCBinCompat::vector<uint32_t> field_2C4;
		MSVCBinCompat::vector<uint32_t> field_2D0;
		ContinuousAttribute<Vector<2, float>> textureTranslation;
		ContinuousAttribute<Vector<2, float>> texturePivot;
		ContinuousAttribute<Vector<3, float>> textureRotation;
		ContinuousAttribute<Matrix<float>> textureDeformation;
		ContinuousAttribute<float> textureOpacity;
		ContinuousAttribute<float> textureBirghtness;
		ContinuousAttribute<float> textureContrast;
		ContinuousAttribute<float> textureSaturation;
		ContinuousAttribute<float> strokeTextureOpacity;
		ContinuousAttribute<float> strokeTextureBrightness;
		ContinuousAttribute<float> strokeTextureContrast;
		ContinuousAttribute<float> strokeTextureSaturation;
		ContinuousAttribute<float> strokeTextureStretch;
		ContinuousAttribute<Matrix<float>> extrusionMatrix;
		DiscreteAttribute<uint32_t> texture;
		DiscreteAttribute<uint32_t> strokeTexture;
		uint32_t field_858;
		uint32_t field_85C;
		uint32_t field_860;
		uint32_t field_864;
		uint32_t field_868;
		uint32_t field_86C;
		uint32_t field_870;
		uint32_t field_874;
		uint32_t field_878;
		uint32_t field_87C;
		uint32_t field_880;
		uint32_t field_884;
		uint32_t field_888;
		uint32_t field_88C;
		uint32_t field_890;
		uint32_t field_894;
		uint32_t field_898;
		uint32_t field_89C;
		uint32_t field_8A0;
		uint32_t field_8A4;
		uint32_t field_8A8;
		uint32_t field_8AC;
		uint32_t field_8B0;
		uint32_t field_8B4;
		uint32_t field_8B8;
		uint32_t field_8BC;
		uint32_t field_8C0;
		uint32_t field_8C4;
		uint32_t field_8C8;
		uint32_t field_8CC;
		uint32_t field_8D0;
		uint32_t field_8D4;
		uint32_t field_8D8;
		uint32_t field_8DC;

		virtual void vf_dtor(uint8_t x) {};
		virtual void vf1();
		virtual void vf2();
		virtual void vf3();
		virtual void vf4();
		virtual void vf5();
		virtual void vf6();
		virtual void vf7();
		virtual void vf8();
		virtual void vf9();
		virtual void vf10();
		virtual void vf11();
		virtual void vf12();
		virtual void vf13();
		virtual void vf14();
		virtual void vf15();
		virtual void vf16();
		virtual void vf17();
		virtual void vf18();
		virtual void vf19();
	};
};