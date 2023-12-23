#include "pchBloxy.h"
#include "OpenGLWindow.h"

#include "Core/Application.h"
#include "Core/Input/Events.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Bloxy
{
    // TODO: Fix Debug Callback
    void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
        GLenum severity, GLsizei length,
        const GLchar* message, const void* data)
    {
        BLOXY_ASSERT(0, "OpenGL Error: id='{0}', message='{1}'", id, message);
    }

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
        glfwSetWindowUserPointer(buffer, &m_Data);

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
                }
            });

        glfwSetCharCallback(buffer, [](GLFWwindow* window, unsigned int codepoint)
            {
                Application::Get()->AddEvent(new CharEvent(codepoint));
            });

        glfwSetMouseButtonCallback(buffer, [](GLFWwindow* window, int button, int action, int mods)
            {
                switch (action)
                {
                case GLFW_PRESS:
                    Application::Get()->AddEvent(new MouseButtonPressEvent(button));
                    break;
                case GLFW_RELEASE:
                    Application::Get()->AddEvent(new MouseButtonReleaseEvent(button));
                    break;
                }
            });

        glfwSetScrollCallback(buffer, [](GLFWwindow* window, double xoffset, double yoffset)
            {
                Application::Get()->AddEvent(new WheelEvent(yoffset));
            });

        glfwSetWindowPosCallback(buffer, [](GLFWwindow* window, int xpos, int ypos) {
            auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            data.ScreenX = xpos;
            data.ScreenY = ypos;
            });

        glfwSetWindowMaximizeCallback(buffer, [](GLFWwindow* window, int maximized) {
            Application::Get()->AddEvent(new WindowMaximizeEvent(maximized));
            });

        glfwSetWindowSizeCallback(buffer, [](GLFWwindow* window, int width, int height) {

            auto& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            data.Width = width;
            data.Height = height;

            glViewport(0, 0, data.Width, data.Height);

            if (data.Width == 0 || data.Height == 0)
                Application::Get()->AddEvent(new WindowMinimizeEvent(true));
            else 
                Application::Get()->AddEvent(new WindowMinimizeEvent(false));

            Application::Get()->AddEvent(new WindowResizeEvent(width, height));
            });

        glfwSetWindowCloseCallback(buffer, [](GLFWwindow* window) {
            Application::Get()->AddEvent(new WindowCloseEvent());
            });

        glfwSetFramebufferSizeCallback(buffer, [](GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        });

        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

        glDebugMessageCallback(GLDebugMessageCallback, nullptr);
	}

    OpenGLWindow::~OpenGLWindow()
    {
        glfwDestroyWindow(std::any_cast<GLFWwindow*>(m_Buffer));
        glfwTerminate();
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