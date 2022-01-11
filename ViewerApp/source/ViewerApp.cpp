#include "ViewerApp.h"
#include "MainWindowForm.h"

namespace Talon
{
	ViewerApp::ViewerApp(HINSTANCE hInst)
		: Application(hInst)
	{
		m_MainWindow = new MainWindowForm(nullptr);
		m_MainWindow->SetName(L"Pteron");
		m_MainWindow->SetDebugName(L"Main Window");
		m_MainWindow->SetPosition((GetSystemMetrics(SM_CXSCREEN) / 2) - (640 / 2), 0);
		m_MainWindow->SetSize(640, 520);
	}

	ViewerApp::~ViewerApp()
	{
		delete m_MainWindow;
	}

	void ViewerApp::Initialize()
	{
		m_MainWindow->Initialize(m_hInst);
		m_MainWindow->SetFocus();
	}
}
