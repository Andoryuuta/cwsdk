#pragma once
/*
	This file takes on the role of globally overriding the `new` and `delete`
	operators to use the same C++ runtime as the game we're injecting into.

	Who knows what issues this could have?
*/

#include <cstdlib>
#include <new.h>


// Global new operator
void* operator new(size_t sz);

// Global delete operator
void operator delete(void* m);

// Global new[] operator
void* operator new[](size_t sz);

// Global delete[] operator
void operator delete[](void* m);