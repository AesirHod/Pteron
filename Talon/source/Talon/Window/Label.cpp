#include <windows.h>

#include "Label.h"

namespace Talon
{
	static const WindowParams DefaultParams
	{
		0,
		L"Static",
		nullptr,
		WS_CHILD | WS_VISIBLE,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	Label::Label(Window* parent)
		: Control(DefaultParams, parent)
	{
	}

	Label::~Label()
	{
	}
}
