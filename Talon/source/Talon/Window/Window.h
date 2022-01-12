#pragma once

#include <list>
#include "../Core.h"

namespace Talon
{
	class Window;

	struct WindowParams
	{
		DWORD exStyle;
		LPCWSTR className;
		LPCWSTR windowName;
		DWORD style;
		int x;
		int y;
		int width;
		int height;
		HMENU menu;
		LPCWSTR debugName;
	};

	class TALON_API Window
	{
	public:
		virtual ~Window();

		virtual void Initialize(HINSTANCE hInst);
		virtual void ShutDown() {};
		void SetFocus();
		void SetName(const WCHAR* name) { m_Params.windowName = name; }
		void SetDebugName(const WCHAR* debugName) { m_Params.debugName = debugName; }
		void SetSize(int weight, int height) { m_Params.width = weight, m_Params.height = height; }
		void SetPosition(int x, int y) { m_Params.x = x, m_Params.y = y; }

		bool GetClientSize(int& x, int&y) const
		{
			RECT rect;
			if (GetClientRect(m_hWnd, &rect))
			{
				x = rect.right - rect.left;
				y = rect.bottom - rect.top;
				return true;
			}

			x = 0;
			y = 0;
			return false;
		}

		HWND GetHwnd() const { return m_hWnd; }

	protected:
		Window(const WindowParams& params, Window* parent);
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		WindowParams m_Params;
		HWND m_hWnd;
		Window* m_Parent;

		std::list<Window*>* m_ChildWindows;
	};
}
