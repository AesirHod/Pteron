#pragma once

#include "../Core.h"
#include "Control.h"

namespace Talon
{
	class TALON_API TextBox : public Control
	{
	public:
		TextBox(Window* parent);
		virtual ~TextBox();

	protected:
		TextBox(const TextBox&) = delete;

		TextBox& operator=(const TextBox&) = delete;
	};
}