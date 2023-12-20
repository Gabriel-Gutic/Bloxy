#pragma once
#include "Window.h"
#include "Input/Event.h"


namespace Bloxy
{
	class Application
	{
	public:
		Application(const std::vector<std::string>& args = {});
		Application(const Application&) = delete;
		~Application();

		void Run();

		static Application* Get();
		static std::unique_ptr<Window>& GetWindow();

		static void Exit();
		static void Exit(int status);

		static Application* Create(const std::vector<std::string>& args = {});
	
		void AddEvent(Event* event);
		void ClearEvents();
	private:
		static Application* s_Instance;

		bool m_IsRunning;
		std::unique_ptr<Window> m_Window;

		std::queue<Event*> m_EventQueue;
	};
}