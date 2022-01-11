#pragma once

#include "../Core.h"
#include "Control.h"

namespace Talon
{
	class TALON_API Button : public Control
	{
	public:
		Button(Window* parent);
		virtual ~Button();

		virtual void HandleCommand(WPARAM wParam) override;

	protected:
		Button(const Control&) = delete;

		Button& operator=(const Button&) = delete;
	};
}