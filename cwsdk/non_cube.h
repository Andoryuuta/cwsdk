#pragma once
#include <cstdint>


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