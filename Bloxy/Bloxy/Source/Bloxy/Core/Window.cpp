#include "pchBloxy.h"
#include "Window.h"

#include "RendererAPI/OpenGL/RendererAPI.h"
#include "RendererAPI/OpenGL/OpenGLWindow.h"


namespace Bloxy
{
	Window::Window(std::string_view title, int width, int height,
		int screenX, int screenY)
		:m_Data(title, width, height, screenX, screenY)
	{

	}

	// Returns the buffer of the Window (GLFWwindow*)
	std::any Window::Get() const
	{
		return m_Buffer;
	}

	void Window::SetTitle(std::string_view title)
	{
		m_Data.Title = title;
	}

	const std::string& Window::GetTitle() const
	{
		return m_Data.Title;
	}

	void Window::SetWidth(int width)
	{
		BLOXY_ASSERT(width > 0, "Window width must be a positive integer! Value '{0}' was given.", width);
		m_Data.Width = width;
	}

	int Window::GetWidth() const
	{
		return m_Data.Width;
	}

	void Window::SetHeight(int height)
	{
		BLOXY_ASSERT(height > 0, "Window height must be a positive integer! Value '{0}' was given.", height);
		m_Data.Height = height;
	}

	int Window::GetHeight() const
	{
		return m_Data.Height;
	}

	void Window::SetSize(int width, int height)
	{
		BLOXY_ASSERT(width > 0, "Window width must be a positive integer! Value '{0}' was given.", width);
		BLOXY_ASSERT(height > 0, "Window height must be a positive integer! Value '{0}' was given.", height);
		m_Data.Width = width;
		m_Data.Height = height;
	}

	float Window::GetAspectRatio()
	{
		return (float)m_Data.Width / (float)m_Data.Height;
	}

	void Window::SetX(int x)
	{
		m_Data.ScreenX = x;
	}

	int Window::GetX() const
	{
		return m_Data.ScreenX;
	}

	void Window::SetY(int y)
	{
		m_Data.ScreenY = y;
	}

	int Window::GetY() const
	{
		return m_Data.ScreenY;
	}

	void Window::SetVSync(bool vsync)
	{
		m_Data.VSync = vsync;
	}

	bool Window::GetVSync() const
	{
		return m_Data.VSync;
	}

	std::unique_ptr<Window> Window::Create()
	{
		switch (RendererAPI::GetBackend())
		{
		case RendererAPI::Backend::OpenGL:
			return std::make_unique<OpenGLWindow>();
		}

		BLOXY_ASSERT(0, "Invalid window type!");
	}
}