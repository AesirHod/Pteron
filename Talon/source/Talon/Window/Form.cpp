#include <windows.h>

#include "../Application.h"
#include "Form.h"
#include "Button.h"

namespace Talon
{
	Form::Form(const WindowParams& params, Window* parent)
		: Window(params, parent)
	{
	}

	Form::~Form()
	{
	}

	LRESULT Form::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_CREATE:
			{
				Application::Log(L"Create \"");
				Application::Log(m_Params.debugName);
				Application::Log(L"\"\n");
				break;
			}
			case WM_DESTROY:
			{
				m_hWnd = 0;
				PostQuitMessage(0);
				Application::Log(L"Destroy \"");
				Application::Log(m_Params.debugName);
				Application::Log(L"\"\n");
				return FALSE;
			}
			case WM_CLOSE:
			{
				Application::Log(L"Close \"");
				Application::Log(m_Params.debugName);
				Application::Log(L"\"\n");
				DestroyWindow(m_hWnd);
				return FALSE;
			}
			case WM_COMMAND:
			{
				// Shouldn't be looping through them all. Try swapping the stl::list for a map to look up the right one.
				for (std::list<Window*>::iterator it = m_ChildWindows->begin(); it != m_ChildWindows->end(); ++it)
				{
					((Control*)(*it))->HandleCommand(wParam);
				}

				break;
			}
			default:
				break;
		}

		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	void Form::InitStyles(HINSTANCE hInst)
	{
		WNDCLASS appWindowClass
		{
			CS_HREDRAW | CS_VREDRAW,
			WndProc,
			0,
			0,
			hInst,
			0, // LoadIcon(application.GetHInst(), MAKEINTRESOURCE(IDI_ESCAPE_ICON)),
			LoadCursor(NULL, IDC_ARROW),
			GetSysColorBrush(COLOR_3DFACE),
			L"",
			L"AppWindow"
		};

		RegisterClass(&appWindowClass);

		WNDCLASS panelClass
		{
			CS_HREDRAW | CS_VREDRAW,
				WndProc,
				0,
				0,
				hInst,
				nullptr, // LoadIcon(application.GetHInst(), MAKEINTRESOURCE(IDI_ESCAPE_ICON)),
				LoadCursor(NULL, IDC_ARROW),
				(HBRUSH)GetStockObject(BLACK_BRUSH),
				L"",
				L"Panel"
		};

		RegisterClass(&panelClass);
	}

	LRESULT CALLBACK Form::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		Form* form = nullptr;

		if (message == WM_NCCREATE)
		{
			form = static_cast<Form*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

			SetLastError(0);
			if (!SetWindowLongPtr(hWnd, GWL_USERDATA, reinterpret_cast<LONG_PTR>(form)))
			{
				if (GetLastError() != 0)
				{
					return FALSE;
				}
			}
		}
		else
		{
			form = reinterpret_cast<Form*>(GetWindowLongPtr(hWnd, GWL_USERDATA));
		}

		if (form)
		{
			return form->HandleMessage(hWnd, message, wParam, lParam);
		}

		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
