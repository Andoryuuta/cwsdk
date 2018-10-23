#include "string.h"

// Binary compatability for MS VC++ 11.0 / _MSC_VER=1700
namespace MSVCBinCompat{
	string::~string()
	{
		// Free memory if cap is greater than sbo size.
		if (cap > 15) {
			delete[] str_data.ptr;
		}
	}

	string::string()
	{
		str_data.ptr = nullptr;
		size = 0;
		cap = 15;
	}

	string::string(const char* c) : string()
	{
		if (c != nullptr)
		{
			auto len = strlen(c);

			// Use SBO if string length is less than 15 + 1(for NULL term) bytes.
			if (len <= 15) {
				memcpy(str_data.sbo, c, len + 1);
				size = len;
			}

			// Otherwise alloc new mem and set ptr.
			else
			{
				char* data = new char[len + 1];
				memcpy(data, c, len + 1);
				str_data.ptr = data;
				size = len;
				cap = len;
			}
		}
		else
		{
			string();
		}
	}

	string::string(std::string s) : string(s.c_str()) {}

	const char* string::c_str()
	{
		if (cap > 15)
		{
			return str_data.ptr;
		}
		else
		{
			return str_data.sbo;
		}
	}

	std::string string::std(){
		return std::string(c_str());
	}

	// Implicit conversion to std::string.
	string::operator std::string() {
		return this->std();
	}

};
