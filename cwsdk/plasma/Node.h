#pragma once

#include <cstdint>
#include "NamedObject.h"

namespace plasma {
	class SmoothMeshShape;
	class Transformation;
	class Display;
	class Widget;

	class Node : NamedObject {
		//void* vtable;
		uint32_t field_20;
		Node* parent_node_or_base_maybe;
		uint32_t children_nodes_linked_list;
		uint32_t unk;
		SmoothMeshShape* shape;
		Transformation* transformation;
		Display* display;
		Widget* related_widget;
		uint32_t field_40;
		uint32_t field_44;
		uint32_t field_48;
		uint32_t field_4C;
		uint32_t field_50;
		uint32_t field_54;
		uint32_t field_58;
		uint32_t field_5C;
		uint32_t field_60;
		uint32_t field_64;
		uint32_t field_68;
		uint32_t field_6C;
		uint32_t field_70;
		uint32_t field_74;
		uint32_t field_78;
		uint32_t field_7C;
		uint32_t field_80;
		uint32_t field_84;
		uint32_t field_88;
		uint32_t field_8C;
		uint32_t field_90;
		uint32_t field_94;
		uint32_t field_98;
		uint32_t field_9C;
		uint32_t field_A0;
		uint32_t field_A4;
		uint32_t field_A8;
		uint32_t field_AC;
		uint32_t field_B0;
		uint32_t field_B4;
		uint32_t field_B8;
		uint32_t field_BC;
		uint32_t field_C0;
		uint32_t field_C4;
		uint32_t field_C8;
		uint32_t field_CC;
		uint32_t field_D0;
		uint32_t field_D4;
		uint32_t field_D8;
		uint32_t field_DC;
		uint32_t field_E0;
		uint32_t field_E4;
		uint32_t field_E8;

		virtual void vf_dtor(uint8_t x) {};
	};
};