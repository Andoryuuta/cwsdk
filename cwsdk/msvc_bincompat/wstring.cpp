#include "wstring.h"

// Binary compatability for MS VC++ 11.0 / _MSC_VER=1700
namespace MSVCBinCompat{
	wstring::~wstring()
	{
		// Free memory if cap is greater than sbo size.
		if (cap > 7) {
			delete[] str_data.ptr;
		}
	}

	wstring::wstring()
	{
		str_data.ptr = nullptr;
		size = 0;
		cap = 7;
	}

	wstring::wstring(const wchar_t* c) : wstring()
	{
		if (c != nullptr)
		{
			auto len = wcslen(c);

			// Use SBO if string length is less than 7 + 1(for NULL term).
			if (len <= 7) {
				memcpy(str_data.sbo, c, (len + 1) * 2);
				size = len;
			}

			// Otherwise alloc new mem and set ptr.
			else
			{
				wchar_t* data = new wchar_t[len + 1];
				memcpy(data, c, (len + 1) * 2);
				str_data.ptr = data;
				size = len;
				cap = len;
			}
		}
		else
		{
			wstring();
		}
	}

	wstring::wstring(std::wstring s) : wstring(s.c_str()) {}

	const wchar_t* wstring::c_str()
	{
		if (cap > 7)
		{
			return str_data.ptr;
		}
		else
		{
			return str_data.sbo;
		}
	}

	std::wstring wstring::std(){
		return std::wstring(c_str());
	}

	// Implicit conversion to std::string.
	wstring::operator std::wstring() {
		return this->std();
	}
};