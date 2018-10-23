#pragma once

#include "../non_cube.h"

namespace cube {
	struct Field
	{
		int vftable;
		int field_4;
		int field_8;
		int field_C;
		int MinZ_Maybe;
		int field_14;
		BlockColor *blocks;
		int MaxZ_Maybe;
	};
};