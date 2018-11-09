#include "wstring.h"

#include <string>

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
	
	void wstring::set(const wchar_t* c)
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
	}

	wstring::wstring(const wchar_t* c) : wstring()
	{
		set(c);
	}

	wstring::wstring(std::wstring s) : wstring(s.c_str()) {}

	wstring::wstring(const wstring& s) : wstring(s.c_str()) {}

	const wchar_t* wstring::c_str() const
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

	void wstring::changed() {
		auto data_ptr = this->c_str();
		auto len = wcslen(data_ptr);
		wchar_t* data = new wchar_t[len + 1];
		memcpy(data, data_ptr, (len + 1) * 2);
		set(data);
		delete[] data;
	}
};

std::wostream& operator<< (std::wostream& os, MSVCBinCompat::wstring& str) {
	os << str.std();
	return os;
}
