#pragma once
#include "Core/Window.h"


namespace Bloxy
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(std::string_view title = "OpenGLWindow", int width = 1280, int height = 720,
			int screenX = 100, int screenY = 100);
		~OpenGLWindow();

		virtual void SetTitle(std::string_view title) override;

		virtual void SetWidth(int width) override;
		virtual void SetHeight(int height) override;
		virtual void SetSize(int width, int height) override;

		virtual void SetVSync(bool vsync) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
	private:
	};
}
