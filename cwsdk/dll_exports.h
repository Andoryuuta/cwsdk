#pragma once


#ifdef _WIN32
#  ifdef CWSDK_EXPORTS
#    define MODULE_API extern "C"  __declspec(dllexport)
#  else
#    define MODULE_API extern "C" __declspec(dllimport)
#  endif
#else
#  define MODULE_API extern "C" 
#endif

MODULE_API void cube_world_print(wchar_t*) {
	auto x = 5;
}