#include "memory_management.h"
#include "cube_funcs.h"
#include <Windows.h>


// Global new operator
void* operator new(size_t sz)
{
	typedef void*(__cdecl* cw_new_t)(size_t);
	static cw_new_t cw_new = nullptr;

	// Lazy init.
	if (cw_new == nullptr) {
		cw_new = (cw_new_t)((uint32_t)GetModuleHandleA(NULL) + 0x28D668);
	}

	return cw_new(sz);
}

// Global delete operator
void operator delete(void* m)
{
	typedef void(__cdecl* cw_delete_t)(void*);
	static cw_delete_t cw_delete = nullptr;
	if (cw_delete == nullptr) {
		cw_delete = (cw_delete_t)((uint32_t)GetModuleHandleA(NULL) + 0x28D66E);
	}

	cw_delete(m);
}

// Global new[] operator
void* operator new[](size_t sz)
{
	typedef void*(__cdecl* cw_new_t)(size_t);
	static cw_new_t cw_new = nullptr;
	if (cw_new == nullptr) {
		cw_new = (cw_new_t)((uint32_t)GetModuleHandleA(NULL) + 0x28D668);
	}

	return cw_new(sz);
}

// Global delete[] operator
void operator delete[](void* m)
{
	typedef void(__cdecl* cw_delete_arr_t)(void*);
	static cw_delete_arr_t cw_delete_arr = nullptr;
	if (cw_delete_arr == nullptr) {
		cw_delete_arr = (cw_delete_arr_t)((uint32_t)GetModuleHandleA(NULL) + 0x28D8CE);
	}

	return cw_delete_arr(m);
}