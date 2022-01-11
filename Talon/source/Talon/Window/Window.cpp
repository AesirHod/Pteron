#include <windows.h>

#include "../Application.h"
#include "Window.h"

namespace Talon
{
	Window::Window(const WindowParams& params, Window* parent)
		: m_Params(params)
		, m_hWnd(0)
		, m_Parent(parent)
		, m_ChildWindows(nullptr)
	{
		m_ChildWindows = new std::list<Window*>();

		if (m_Parent)
		{
			m_Parent->m_ChildWindows->push_back(this);
		}
	}

	Window::~Window()
	{
		if (m_Parent)
		{
			m_Parent->m_ChildWindows->remove(this);
		}

		while (!m_ChildWindows->empty())
		{
			Window* child = m_ChildWindows->back();
			m_ChildWindows->pop_back();
			delete child;
		}
	}

	void Window::Initialize(HINSTANCE hInst)
	{
		if (m_hWnd == 0)
		{
			m_hWnd = CreateWindowEx(
				m_Params.exStyle,
				m_Params.className,
				m_Params.windowName,
				m_Params.style,
				m_Params.x,
				m_Params.y,
				m_Params.width,
				m_Params.height,
				(m_Parent) ? m_Parent->m_hWnd : nullptr,
				m_Params.menu,
				hInst,
				this
			);
		}

		for (std::list<Window*>::iterator it = m_ChildWindows->begin(); it != m_ChildWindows->end(); ++it)
		{
			(*it)->Initialize(hInst);
		}

		ShowWindow(m_hWnd, TRUE);
		UpdateWindow(m_hWnd);
	}

	void Window::SetFocus()
	{
		::SetFocus(m_hWnd);
	}
}