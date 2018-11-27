#pragma once
#include <cstdint>
#include <cstring>
#include "Vector3.h"


struct Color {
	float r, g, b, a;
	Color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}

	static Color Black()	{ return Color(0, 0, 0, 1); }
	static Color White()	{ return Color(1, 1, 1, 1); }

	static Color Red()		{ return Color(1, 0, 0, 1); }
	static Color Green()	{ return Color(0, 1, 0, 1); }
	static Color Blue()		{ return Color(0, 0, 1, 1); }
};



struct STDMapBinTreeNode;
struct ChunksArray;
struct BlockColor;

/* 90 */
struct STDList
{
	void *_MyHead;
	int _MySize;
};

/* 97 */
struct STDMap
{
	STDMapBinTreeNode *field_0;
	int field_4;
};
/* 98 */
struct STDMapBinTreeNode
{
	STDMapBinTreeNode *right;
	STDMapBinTreeNode *parent;
	STDMapBinTreeNode *left;
	char unk_bool;
	char entry_empty;
	char field_E;
	char field_F;
	int field_10;
};


/* 102 */
struct STDVector
{
	uint32_t Start;
	uint32_t End;
	uint32_t Cap;
};

/* 106 */
struct RBBST_node
{
	RBBST_node *left;
	RBBST_node *parent;
	RBBST_node *right;
	char color;
	char isnil;
	__int16 _pad;
};

/* 107 */
struct map_uint64_uint32_node
{
	RBBST_node node_base;
	signed __int64 key;
	int value;
};

/* 130 */
struct ItemAdaption
{
	uint8_t x;
	uint8_t y;
	uint8_t z;
	uint8_t material;
	uint16_t unk_level_maybe;
	uint16_t _pad;
};

/* 113 */
struct Item
{
	uint8_t category_id;
	uint8_t item_id;
	uint8_t field_2;
	uint8_t field_3;
	int32_t modifier;
	int32_t field_8;
	uint8_t rarity;
	uint8_t material;
	uint8_t adapted;
	uint8_t field_F;
	uint16_t level;
	uint16_t field_12;
	ItemAdaption customization_data[32];
	int32_t adaption_count;
};


/* 114 */
struct WornEquipment
{
	Item unk;
	Item necklace;
	Item chest;
	Item feet;
	Item hands;
	Item shoulder;
	Item left_weapon;
	Item right_weapon;
	Item left_ring;
	Item right_ring;
	Item light;
	Item special;
	Item pet;
};

/**/
struct zone_pickupable_object
{
	Item item;
	Vector3<int64_t> position;
	float rotation;
	float scale;
	uint32_t field_138;
	uint32_t time_before_drop_spin_animation_completes_ms;
	uint32_t time_before_rendering_ms;
	uint32_t field_144; // Related to a row in the world*.db called 'time'. This field is usually set to -1 / 0xFFFFFFFF.

	zone_pickupable_object() {

		// This ctor should be easily replaced by setting the default values the same.
		/*
		auto imageBase = (uint32_t)GetModuleHandleA(NULL);
		typedef zone_pickupable_object* (__thiscall* zone_pickupable_object_ctor_t)(zone_pickupable_object*);
		auto zone_pickupable_object_ctor = (zone_pickupable_object_ctor_t)(imageBase + 0x4A970);
		zone_pickupable_object_ctor(this);
		*/

		this->item.level = 1;
		this->item.category_id = 0;
		this->item.item_id = 0;
		this->item.field_8 = 0;
		this->item.rarity = 0;
		this->item.material = 0;
		this->item.adapted = 0;
		this->item.adaption_count = 0;
		memset(&this->item.customization_data, 0, 0x100);
		this->scale = 0.071428575f;
		this->field_138 = 0;
		this->time_before_drop_spin_animation_completes_ms = 0;
		this->time_before_rendering_ms = 0;
		this->field_144 = -1;

	}
};

struct zone_static_object
{
	uint32_t type;
	uint32_t field_4;
	Vector3<int64_t> position;
	uint32_t cuwo_orientation;
	uint32_t vis_scale;
	uint32_t phys_scale;
	uint32_t height;
	uint32_t field_30;
	uint32_t some_timer;
	uint32_t field_38;
	uint32_t field_3C;
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
	uint32_t field_EC;
	uint32_t field_F0;
	uint32_t field_F4;
	uint32_t field_F8;
	uint32_t field_FC;
	uint32_t field_100;
	uint32_t field_104;
	uint32_t field_108;
	uint32_t field_10C;
	uint32_t field_110;
	uint32_t field_114;
	uint32_t field_118;
	uint32_t field_11C;
	uint32_t field_120;
	uint32_t field_124;
	uint32_t field_128;
	uint32_t field_12C;
	uint32_t field_130;
	uint32_t field_134;
	uint32_t field_138;
	uint32_t field_13C;
	uint32_t field_140;
	uint32_t field_144;
	uint32_t field_148;
	uint32_t field_14C;
	uint32_t field_150;
	uint32_t field_154;
	uint32_t field_158;
	uint32_t field_15C;
	uint32_t field_160;
	uint32_t field_164;
	uint32_t field_168;
	uint32_t field_16C;
	uint32_t field_170;
	uint32_t field_174;
	uint32_t field_178;
	uint32_t field_17C;
	uint32_t field_180;
	uint32_t field_184;
};

/* 129 */
struct BlockColor
{
	uint8_t Red;
	uint8_t Green;
	uint8_t Blue;
	uint8_t Type;

	BlockColor(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _type) : Red(_r), Green(_g), Blue(_b), Type(_type) {}
};


struct Category
{
	union {
		struct {
			uint32_t CategoryID;
			uint32_t ItemID;
		};
		uint64_t whole;
	};
	

	friend bool operator<(const Category& l, const Category& r)
	{
		if (l.CategoryID == r.CategoryID) {
			return l.ItemID < r.ItemID;
		}
		else {
			return l.CategoryID < r.CategoryID;
		}
	}
};