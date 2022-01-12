#pragma once

#include <windows.h>

#include "Core.h"

namespace Talon
{
	class TALON_API Application
	{
	public:
		HINSTANCE GetHInst() const { return m_hInst; }

	protected:
		Application(HINSTANCE hInst);
		Application(const Application&) = delete;
		virtual ~Application();

		Application& operator=(const Application&) = delete;

		virtual void Initialize();
		virtual void MainLoop();
		virtual void Idle() {}

		HINSTANCE m_hInst;

	public:
		static inline Application* GetInstance() { return s_Instance; }

		template<typename T>
		static void Run(HINSTANCE hInst)
		{
			if (!s_Instance)
			{
				s_Instance = new T(hInst);
				s_Instance->Initialize();
				s_Instance->MainLoop();
			}

			delete s_Instance;
			s_Instance = nullptr;
		}

		static void Log(const WCHAR* message)
		{
			OutputDebugString(message);
		}

	private:
		static Application* s_Instance;
	};
}