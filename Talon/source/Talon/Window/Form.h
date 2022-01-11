#pragma once

#include "../Core.h"
#include "Window.h"

namespace Talon
{
	class TALON_2_API Form : public Window
	{
	public:
		virtual ~Form();

		virtual LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	protected:
		Form(const WindowParams& params, Window* parent);
		Form(const Form&) = delete;

		Form& operator=(const Form&) = delete;

	public:
		static void InitStyles(HINSTANCE hInst);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}