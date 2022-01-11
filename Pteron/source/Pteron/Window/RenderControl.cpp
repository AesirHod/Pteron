#include <windows.h>

#include "RenderControl.h"

using namespace Talon;

namespace Pteron
{
	static const WindowParams DefaultParams
	{
		0,
		L"Panel",
		nullptr,
		WS_CHILD,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	RenderControl::RenderControl(Window* parent)
		: Form(DefaultParams, parent)
	{
	}

	RenderControl::~RenderControl()
	{
	}

	LRESULT RenderControl::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return Form::HandleMessage(hWnd, message, wParam, lParam);
	}
}
