#pragma once

#include "../Core.h"
#include "Talon/Window/Form.h"

using namespace Talon;

namespace Pteron
{
	class PTERON_API RenderControl : public Form
	{
	public:
		RenderControl(Window* parent);
		virtual ~RenderControl();

		virtual void Initialize(HINSTANCE hInst) override;
		virtual void ShutDown() override;
		virtual LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	protected:
		RenderControl(const RenderControl&) = delete;

		RenderControl& operator=(const RenderControl&) = delete;
	};
}
