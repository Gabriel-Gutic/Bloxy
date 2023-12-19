#include "pchBloxy.h"
#include "Application.h"

#include "Time/Time.h"


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
	}

	Application::~Application()
	{
		Time::Destroy();
	}

	void Application::Run()
	{
		m_Window->SetVSync(true);

		while (m_IsRunning)
		{
			Time::CountFPS();

			m_Window->SetTitle(std::to_string(Time::GetFPS()));

			// if (glfwGetKey(std::any_cast<GLFWwindow*>(m_Window->Get()), GLFW_KEY_ENTER))
			// {
			// 	m_Window->SetSize(500, 500);
			// }

			m_Window->SwapBuffers();
			m_Window->PollEvents();
		}
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
}