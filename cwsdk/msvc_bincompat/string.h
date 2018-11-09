#pragma once
#include <cstdint>
#include <string>

// Binary compatability for MS VC++ 11.0 / _MSC_VER=1700
namespace MSVCBinCompat{
	class string
	{
		union
		{
			char* ptr;
			char sbo[16];
		} str_data;
		uint32_t size;
		uint32_t cap;

	public:
		~string();
		string();
		void set(const char* c);
		string(const char* c);
		string(std::string s);
		string(const string& s);
		const char* c_str() const;
		std::string std();
		operator std::string();
		void changed();
	};
};

std::ostream& operator<< (std::ostream& os, MSVCBinCompat::string& dt);
