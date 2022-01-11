#pragma once

#include "../Core.h"
#include "Control.h"

namespace Talon
{
	class TALON_API ComboBox : public Control
	{
	public:
		ComboBox(Window* parent);
		virtual ~ComboBox();

	protected:
		ComboBox(const ComboBox&) = delete;

		ComboBox& operator=(const ComboBox&) = delete;
	};
}