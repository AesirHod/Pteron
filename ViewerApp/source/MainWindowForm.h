#pragma once

#include "Talon/Window/Form.h"

namespace Talon
{
	class MainWindowForm : public Form
	{
	public:
		MainWindowForm(Window* parent);
		virtual ~MainWindowForm();

		virtual LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	protected:
		MainWindowForm(const MainWindowForm&) = delete;

		MainWindowForm& operator=(const MainWindowForm&) = delete;
	};
}
