#include <windows.h>

#include "Button.h"

namespace Talon
{
	static const WindowParams DefaultParams
	{
		0,
		L"Button",
		nullptr,
		BS_PUSHBUTTON /*| BS_ICON*/ | WS_CHILD | WS_VISIBLE,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	Button::Button(Window* parent)
		: Control(DefaultParams, parent)
	{
	}

	Button::~Button()
	{
	}

	void Button::HandleCommand(WPARAM wParam)
	{
		Control::HandleCommand(wParam);

		switch ((HIWORD(wParam)))
		{
			case BN_CLICKED:
			{
				break;
			}
		}
	}
}
