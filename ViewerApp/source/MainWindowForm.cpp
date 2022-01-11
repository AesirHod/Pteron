#include <windows.h>

#include "MainWindowForm.h"
#include "Talon/Application.h"
#include "Talon/Window/Button.h"
#include "Talon/Window/CheckBox.h"
#include "Talon/Window/ComboBox.h"
#include "Talon/Window/Label.h"
#include "Talon/Window/TextBox.h"
#include "Pteron/Window/RenderControl.h"

namespace Talon
{
	static const WindowParams DefaultParams
	{
		0,
		L"AppWindow",
		nullptr,
		WS_OVERLAPPEDWINDOW, // WS_POPUP,
		0,
		0,
		0,
		0,
		nullptr,
		nullptr
	};

	MainWindowForm::MainWindowForm(Window* parent)
		: Form(DefaultParams, parent)
	{
		Pteron::RenderControl* renderControl = new Pteron::RenderControl(this);
		renderControl->SetName(L"Play");
		renderControl->SetDebugName(L"Play Button");
		renderControl->SetPosition(10, 10);
		renderControl->SetSize(600, 400);

		//auto btn = new ComboBox(this);
		//btn->SetName(L"Play");
		//btn->SetDebugName(L"Play Button");
		//btn->SetPosition(20, 420);
		//btn->SetSize(100, 20);
	}

	MainWindowForm::~MainWindowForm()
	{
	}

	LRESULT MainWindowForm::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return Form::HandleMessage(hWnd, message, wParam, lParam);
	}
}
