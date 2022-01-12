#include <windows.h>

#include "RenderControl.h"
#include "../DeviceManager.h"

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

	void RenderControl::Initialize(HINSTANCE hInst)
	{
		Form::Initialize(hInst);

		DeviceManager::Create();
		DeviceManager::GetInstance()->Initialize(this);
	}

	void RenderControl::ShutDown()
	{
		DeviceManager::GetInstance()->ShutDown();
		DeviceManager::Destroy();

		Form::ShutDown();
	}

	LRESULT RenderControl::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return Form::HandleMessage(hWnd, message, wParam, lParam);
	}
}
