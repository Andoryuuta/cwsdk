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
	int Start;
	int End;
	int Cap;
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
	char x;
	char y;
	char z;
	char material;
	__int16 unk_level_maybe;
	__int16 _pad;
};

/* 113 */
struct Item
{
	char category_id;
	char item_id;
	char field_2;
	char field_3;
	int modifier;
	int field_8;
	char rarity;
	char material;
	char adapted;
	char field_F;
	__int16 level;
	__int16 field_12;
	ItemAdaption customization_data[32];
	int adaption_count;
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
