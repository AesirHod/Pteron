#pragma once

#include "Talon/Application.h"

namespace Talon
{
	class MainWindowForm;

	class ViewerApp : public Application
	{
	public:
		ViewerApp(HINSTANCE hInst);
		virtual ~ViewerApp();

		void Initialize() override;

	protected:
		ViewerApp(const ViewerApp&) = delete;

		ViewerApp& operator=(const ViewerApp&) = delete;

		Talon::MainWindowForm* m_MainWindow;
	};
}
