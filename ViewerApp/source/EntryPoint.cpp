#include <windows.h>

#include "ViewerApp.h"
#include "Talon/Window/Form.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Talon::Form::InitStyles(hInstance);
	Talon::Application::Run<Talon::ViewerApp>(hInstance);

	return 0;
}
