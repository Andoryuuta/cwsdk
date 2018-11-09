#include "Creature.h"
#include <math.h>
#include <locale>
#include <codecvt>
#include <string>

#include "../msvc_bincompat.h"
#include "../cube_funcs.h"

namespace cube {
	std::wstring Creature::GetName()
	{
		auto len = strnlen_s(this->name, 16);
		if (len == 0)
		{

			MSVCBinCompat::wstring compat;
			if (this->hostility_flags == 3 || this->movement_flags & 0x200)
			{
				// "Rare" creature names
				cube_funcs::instance()->generate_rare_creature_name(&compat, (uint32_t)this->GUID, this->race);
				return compat;
			}
			else
			{
				// "Normal" creature names.

				// This is AWFUL for performance because it copies out the entire map. please fix me when I implement search in MSVCBinCompat::map.
				auto gc = cube::GetGameController();
				auto entity_localization_map = gc->world.EntityNames->CopyToSTDMap();
				auto localization_key = entity_localization_map.find(this->race);
				if (localization_key == entity_localization_map.end())
				{
					return compat;
				}
				else
				{
					MSVCBinCompat::wstring out;
					MSVCBinCompat::wstring key = localization_key->second;
					MSVCBinCompat::wstring word_form = L"singular";

					cube_funcs::instance()->speech_get_localization_from_dict(&gc->world.speech, &out, &key, word_form);

					return out;
				}
			}
		}
		else
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			std::wstring wide = converter.from_bytes(this->name);
			return wide;
		}
	}

	double Creature::DistanceFrom(Vector3<int64_t> point) {
		auto p1 = this->position;
		auto p2 = point;

		auto x = p1.X - p2.X;
		auto y = p1.Y - p2.Y;
		auto z = p1.Z - p2.Z;

		return sqrt((x*x) + (y*y) + (z*z));
	}
	double Creature::DistanceFrom(Creature* target) {
		return DistanceFrom(target->position);
	}
};