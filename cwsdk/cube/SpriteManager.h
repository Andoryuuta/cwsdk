#pragma once

#include <cstdint>
#include "../msvc_bincompat.h"
#include "../dx9_stub.h"

namespace cube {
	struct Sprite;

	struct SpriteManager
	{
		uint32_t vtable;
		MSVCBinCompat::vector<Sprite*> sprites;
		LPDIRECT3DDEVICE9 D3D9Device;
	};
};