#pragma once

#include "../Core.h"
#include "Control.h"

namespace Talon
{
	class TALON_API Label : public Control
	{
	public:
		Label(Window* parent);
		virtual ~Label();

	protected:
		Label(const Label&) = delete;

		Label& operator=(const Label&) = delete;
	};
}