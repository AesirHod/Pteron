#include <windows.h>

#include "CheckBox.h"

namespace Talon
{
	static const WindowParams DefaultParams
	{
		0,
		L"Button", // A checkbox is a type of button
		nullptr,
		BS_CHECKBOX | WS_CHILD | WS_VISIBLE,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	CheckBox::CheckBox(Window* parent)
		: Control(DefaultParams, parent)
	{
	}

	CheckBox::~CheckBox()
	{
	}

	void CheckBox::HandleCommand(WPARAM wParam)
	{
		Control::HandleCommand(wParam);

		switch ((HIWORD(wParam)))
		{
			case BN_CLICKED:
			{
				BOOL checked = IsDlgButtonChecked(m_Parent->GetHwnd(), 0);
				if (checked)
				{
					CheckDlgButton(m_Parent->GetHwnd(), 0, BST_UNCHECKED);
				}
				else
				{
					CheckDlgButton(m_Parent->GetHwnd(), 0, BST_CHECKED);
				}
				break;
			}
		}
	}
}
