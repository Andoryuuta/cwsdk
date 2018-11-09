#pragma once
#include <iostream>
#include <cstdint>
#include <string>

// Binary compatability for MS VC++ 11.0 / _MSC_VER=1700
namespace MSVCBinCompat {
	class wstring
	{
		union
		{
			wchar_t* ptr;
			wchar_t sbo[8];
		} str_data;
		uint32_t size;
		uint32_t cap;

	public:
		~wstring();
		wstring();
		void set(const wchar_t* c);
		wstring(const wchar_t* c);
		wstring(std::wstring s);
		wstring(const wstring& s);
		const wchar_t* c_str() const;
		std::wstring std();
		operator std::wstring();
		void changed();
	};
}

std::wostream& operator<< (std::wostream& os, MSVCBinCompat::wstring& dt);
