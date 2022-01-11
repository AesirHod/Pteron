#include "Application.h"

namespace Talon
{
	Application* Application::s_Instance = nullptr;

	Application::Application(HINSTANCE hInst)
		: m_hInst(hInst)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize()
	{
	}

	void Application::MainLoop()
	{
		while (true)
		{
			MSG msg;

			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					break;
				}

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Idle();
			}
		}
	}
}