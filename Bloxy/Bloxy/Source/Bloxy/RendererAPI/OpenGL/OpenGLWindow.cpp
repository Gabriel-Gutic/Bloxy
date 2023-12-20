#include "pchBloxy.h"
#include "OpenGLWindow.h"

#include "Core/Application.h"
#include "Core/Input/Events.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Bloxy
{
	OpenGLWindow::OpenGLWindow(std::string_view title, int width, int height, int screenX, int screenY)
		:Window(title, width, height, screenX, screenY)
	{
        /* Initialize the library */
        BLOXY_ASSERT(glfwInit(), "Failed to initialize GLFW!");

        /* Create a windowed mode window and its OpenGL context */
        GLFWwindow* buffer = glfwCreateWindow(width, height, title.data(), NULL, NULL);
        BLOXY_ASSERT(buffer, "Failed to create GLFWwindow!");
        m_Buffer = buffer;

        /* Make the window's context current */
        glfwMakeContextCurrent(buffer);

        // Init Glad
        BLOXY_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize Glad!");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        glEnable(GL_DEPTH_TEST);

        SetVSync(false);

        glfwSetKeyCallback(buffer, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                switch (action)
                {
                case GLFW_PRESS:
                    Application::Get()->AddEvent(new KeyPressEvent(key));
                    break;
                case GLFW_RELEASE:
                    Application::Get()->AddEvent(new KeyReleaseEvent(key));
                    break;
                case GLFW_REPEAT:
                    Application::Get()->AddEvent(new KeyRepeatEvent(key));
                    break;
                }
            });

        glfwSetFramebufferSizeCallback(buffer, [](GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        });
	}

    void OpenGLWindow::SetTitle(std::string_view title)
    {
        glfwSetWindowTitle(std::any_cast<GLFWwindow*>(m_Buffer), title.data());
        Window::SetTitle(title);
    }

    void OpenGLWindow::SetWidth(int width)
    {
        SetSize(width, m_Data.Height);
    }

    void OpenGLWindow::SetHeight(int height)
    {
        SetSize(m_Data.Width, height);
    }

    void OpenGLWindow::SetSize(int width, int height)
    {
        glfwSetWindowSize(std::any_cast<GLFWwindow*>(m_Buffer), width, height);
    
        Window::SetSize(width, height);
    }

    void OpenGLWindow::SetVSync(bool vsync)
    {
        glfwSwapInterval(vsync ? 1 : 0);
        Window::SetVSync(vsync);
    }

    void OpenGLWindow::SwapBuffers()
    {
        glfwSwapBuffers(std::any_cast<GLFWwindow*>(m_Buffer));
    }

    void OpenGLWindow::PollEvents()
    {
        glfwPollEvents();
    }
}