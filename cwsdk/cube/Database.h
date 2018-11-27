#pragma once

#include <cstdint>

namespace cube {
	struct Database
	{
		uint32_t vtable;
		void* some_sqlite_obj;
	};
};
