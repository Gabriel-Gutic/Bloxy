#include "pchBloxy.h"
#include "Application.h"

#include "Time/Time.h"
#include "Input/Input.h"


namespace Bloxy
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const std::vector<std::string>& args)
		:m_IsRunning(true)
	{
		BLOXY_ASSERT(!s_Instance, "Application already initialized!");
		s_Instance = this;

		s_Instance->m_Window = std::move(Window::Create());

		Time::Init();
		Input::Init();
	}

	Application::~Application()
	{
		ProcessEvents();
		Input::Get()->Reset();

		RemoveAllLayers();
		Input::Destroy();
		Time::Destroy();
	}

	void Application::Run()
	{
		m_Window->SetVSync(true);

		while (m_IsRunning)
		{
			Time::CountFPS();

			ProcessEvents();

			for (auto&[name, layer] : m_Layers)
			{
				layer->OnUpdate();
			}

			m_Window->SwapBuffers();
			m_Window->PollEvents();

			Input::Get()->Reset();
		}
	}

	Application* Application::Get()
	{
		return s_Instance;
	}

	std::unique_ptr<Window>& Application::GetWindow()
	{
		return s_Instance->m_Window;
	}

	void Application::AddLayer(const std::string& name, Layer* layer)
	{
		BLOXY_ASSERT(s_Instance->m_Layers.find(name) == s_Instance->m_Layers.end(),
			"There is already a layer with the name '{0}'", name);
		s_Instance->m_Layers[name] = layer;
	}

	Layer* Application::GetLayer(const std::string& name)
	{
		BLOXY_ASSERT(s_Instance->m_Layers.find(name) != s_Instance->m_Layers.end(),
			"The is no layer with the name '{0}'", name);
		return s_Instance->m_Layers[name];
	}

	void Application::RemoveLayer(const std::string& name)
	{
		BLOXY_ASSERT(s_Instance->m_Layers.find(name) != s_Instance->m_Layers.end(),
			"The is no layer with the name '{0}'", name);
		delete s_Instance->m_Layers[name];
		s_Instance->m_Layers.erase(name);
	}

	void Application::RemoveAllLayers()
	{
		for (auto&[name, layer] : s_Instance->m_Layers)
		{
			delete layer;
		}
		s_Instance->m_Layers.clear();
	}

	void Application::Exit()
	{
		s_Instance->m_IsRunning = false;

	}

	void Application::Exit(int status)
	{
		exit(status);
	}

	void Application::AddEvent(Event* event)
	{
		m_EventQueue.push(event);
	}

	void Application::ProcessEvents()
	{
		while (!m_EventQueue.empty())
		{
			Input::Get()->AttachEvent(*m_EventQueue.front());
			delete m_EventQueue.front();
			m_EventQueue.pop();
		}
	}
}