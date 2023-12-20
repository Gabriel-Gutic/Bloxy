#pragma once
#include "Core/Input/Input.h"


namespace Bloxy
{
	class OpenGLInput : public Input
	{
	public:
		OpenGLInput(){}
		virtual bool GetKeyStatus(int keycode) override;
	};
}