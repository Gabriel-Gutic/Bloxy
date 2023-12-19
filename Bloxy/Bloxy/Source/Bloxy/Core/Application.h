#pragma once
#include "Window.h"


namespace Bloxy
{
	class Application
	{
	public:
		Application(const std::vector<std::string>& args = {});
		Application(const Application&) = delete;
		~Application();

		void Run();

		static std::unique_ptr<Window>& GetWindow();

		static void Exit();
		static void Exit(int status);

		static Application* Create(const std::vector<std::string>& args = {});
	private:
		static Application* s_Instance;

		bool m_IsRunning;
		std::unique_ptr<Window> m_Window;
	};
}