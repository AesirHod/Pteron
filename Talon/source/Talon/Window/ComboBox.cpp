#include <windows.h>

#include "ComboBox.h"

namespace Talon
{
	static const WindowParams DefaultParams
	{
		0,
		L"ComboBox",
		nullptr,
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	ComboBox::ComboBox(Window* parent)
		: Control(DefaultParams, parent)
	{
	}

	ComboBox::~ComboBox()
	{
	}
}
