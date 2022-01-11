#pragma once

#include "../Core.h"
#include "Window.h"

namespace Talon
{
	class TALON_API Control : public Window
	{
	public:
		Control(const WindowParams& params, Window* parent);
		virtual ~Control();

		virtual void Initialize(HINSTANCE hInst) override;
		virtual void HandleCommand(WPARAM wParam);

	protected:
		Control(const Control&) = delete;

		Control& operator=(const Control&) = delete;

	protected:
		static LRESULT CALLBACK SubclassProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR subClassId, DWORD_PTR refData);
	};
}