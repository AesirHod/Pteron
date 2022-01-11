#pragma once

#include "../Core.h"
#include "Control.h"

namespace Talon
{
	class TALON_API CheckBox : public Control
	{
	public:
		CheckBox(Window* parent);
		virtual ~CheckBox();

		virtual void HandleCommand(WPARAM wParam) override;

	protected:
		CheckBox(const CheckBox&) = delete;

		CheckBox& operator=(const CheckBox&) = delete;
	};
}