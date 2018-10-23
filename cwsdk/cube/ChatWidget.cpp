#include "ChatWidget.h"
#include "../msvc_bincompat.h"
#include "../cube_funcs.h"

namespace cube {
	void ChatWidget::Print(std::wstring str, Color color) {
		MSVCBinCompat::wstring compat = str;

		cube_funcs::instance()->chatwidget_print((uint32_t)this, &compat, &color);
	}
};