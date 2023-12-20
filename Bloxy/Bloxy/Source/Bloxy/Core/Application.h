#pragma once
#include "Window.h"
#include "Input/Event.h"
#include "Layer.h"



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

		static void AddLayer(const std::string& name, Layer* layer);
		static Layer* GetLayer(const std::string& name);
		static void RemoveLayer(const std::string& name);
		static void RemoveAllLayers();

		static void Exit();
		static void Exit(int status);

		static Application* Create(const std::vector<std::string>& args = {});
	
		void AddEvent(Event* event);
		void ProcessEvents();
	private:
		static Application* s_Instance;

		bool m_IsRunning;
		std::unique_ptr<Window> m_Window;

		std::queue<Event*> m_EventQueue;
		std::queue<Event*> m_WindowEventQueue;
		std::unordered_map<std::string, Layer*> m_Layers;
	};
}