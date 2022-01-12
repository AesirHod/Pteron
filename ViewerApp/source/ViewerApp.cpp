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
		m_MainWindow->SetPosition((GetSystemMetrics(SM_CXSCREEN) / 2) - (959 / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (674 / 2));
		m_MainWindow->SetSize(959, 674);
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
