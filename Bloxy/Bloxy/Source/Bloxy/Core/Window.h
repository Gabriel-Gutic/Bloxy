#pragma once


namespace Bloxy
{
	struct WindowData
	{
		std::string Title;
		int Width;
		int Height;

		// Screen Position
		int ScreenX;
		int ScreenY;

		bool VSync;

		WindowData(std::string_view title, int width, int height,
			int screenX, int screenY)
			:Title(title),
			Width(width),
			Height(height),
			ScreenX(screenX),
			ScreenY(screenY),
			VSync(false)
		{
		}
	};

	class Window
	{
	public:
		Window(std::string_view title, int width, int height,
			int screenX, int screenY);
		virtual ~Window(){}

		std::any Get() const;

		virtual void SetTitle(std::string_view title);
		virtual const std::string& GetTitle() const;

		virtual void SetWidth(int width);
		virtual int GetWidth() const;
		virtual void SetHeight(int height);
		virtual int GetHeight() const;
		virtual void SetSize(int width, int height);

		virtual float GetAspectRatio();

		virtual void SetX(int x);
		virtual int GetX() const;
		virtual void SetY(int y);
		virtual int GetY() const;

		virtual void SetVSync(bool vsync);
		virtual bool GetVSync() const;

		virtual void SwapBuffers(){}
		virtual void PollEvents(){}

		static std::unique_ptr<Window> Create();
	protected:
		WindowData m_Data;
		std::any m_Buffer;
	};
}