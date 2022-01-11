#include <windows.h>
#include <commctrl.h>

#include "Control.h"
#include "../Application.h"

namespace Talon
{
	Control::Control(const WindowParams& params, Window* parent)
		: Window(params, parent)
	{
	}

	Control::~Control()
	{
	}

	void Control::Initialize(HINSTANCE hInst)
	{
		if (m_hWnd == 0)
		{
			Application::Log(L"Create \"");
			Application::Log(m_Params.debugName);
			Application::Log(L"\"\n");
		}

		Window::Initialize(hInst);

		if (m_hWnd != 0)
		{
			SetWindowSubclass(m_hWnd, SubclassProc, 1, (DWORD_PTR)this);
		}
	}

	void Control::HandleCommand(WPARAM wParam)
	{
	}

	LRESULT CALLBACK Control::SubclassProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR subClassId, DWORD_PTR refData)
	{
		Control* window = (Control*)refData;

		switch (msg)
		{
			case WM_CREATE:
			{
				break;
			}
			case WM_DESTROY:
			{
				window->m_hWnd = 0;
				Application::Log(L"Destroy \"");
				Application::Log(window->m_Params.debugName);
				Application::Log(L"\"\n");
				break;
			}
			default:
				break;
		}

		return DefSubclassProc(hWnd, msg, wParam, lParam);
	}
}
