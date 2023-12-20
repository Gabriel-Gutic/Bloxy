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
		Input::Destroy();
		Time::Destroy();
	}

	void Application::Run()
	{
		m_Window->SetVSync(true);

		while (m_IsRunning)
		{
			Time::CountFPS();

			while (!m_EventQueue.empty())
			{
				Input::Get()->AttachEvent(*m_EventQueue.front());
				delete m_EventQueue.front();
				m_EventQueue.pop();
			}

			m_Window->SetTitle(std::to_string(Time::GetFPS()));

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

	void Application::ClearEvents()
	{
		// for (Event* event : m_EventQueue)
		// {
		// 	delete event;
		// }
		// m_EventQueue.clear();
	}
}