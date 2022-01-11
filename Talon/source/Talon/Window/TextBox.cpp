#include <windows.h>

#include "TextBox.h"

namespace Talon
{
	static const WindowParams DefaultParams
	{
		WS_EX_CLIENTEDGE,
		L"Edit",
		nullptr,
		WS_BORDER | ES_LEFT | WS_CHILD | WS_VISIBLE,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	TextBox::TextBox(Window* parent)
		: Control(DefaultParams, parent)
	{
	}

	TextBox::~TextBox()
	{
	}
}
