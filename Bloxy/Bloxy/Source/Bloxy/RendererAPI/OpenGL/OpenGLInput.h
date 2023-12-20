#pragma once
#include "Core/Input/Input.h"


namespace Bloxy
{
	class OpenGLInput : public Input
	{
	public:
		OpenGLInput(){}
		virtual bool GetKeyState(int keycode) override;
		virtual bool GetMouseButtonState(int button) override;
		virtual glm::vec2 MousePositionRetriever() override;
	};
}