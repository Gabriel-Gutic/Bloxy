#include "pchBloxy.h"
#include "OpenGLInput.h"

#include "Core/Application.h"

#include <GLFW/glfw3.h>


namespace Bloxy
{
	bool OpenGLInput::GetKeyState(int keycode)
	{
		GLFWwindow* window;
		try
		{
			window = std::any_cast<GLFWwindow*>(Application::GetWindow()->Get());
		} 
		catch (std::bad_any_cast exec)
		{
			ASSERT(0, "Invalid Window Cast!");
		}

		int status = GLFW_RELEASE;
		switch (keycode)
		{
		case BLOXY_KEY_SHIFT:
			if (glfwGetKey(window, BLOXY_KEY_LEFT_SHIFT) + glfwGetKey(window, BLOXY_KEY_RIGHT_SHIFT) > 0)
				status = GLFW_PRESS;
			break;
		case BLOXY_KEY_ALT:
			if (glfwGetKey(window, BLOXY_KEY_LEFT_ALT) + glfwGetKey(window, BLOXY_KEY_RIGHT_ALT) > 0)
				status = GLFW_PRESS;
			break;
		case BLOXY_KEY_CONTROL:
			if (glfwGetKey(window, BLOXY_KEY_LEFT_CONTROL) + glfwGetKey(window, BLOXY_KEY_RIGHT_CONTROL) > 0)
				status = GLFW_PRESS;
			break;
		case BLOXY_KEY_SUPER:
			if (glfwGetKey(window, BLOXY_KEY_LEFT_SUPER) + glfwGetKey(window, BLOXY_KEY_RIGHT_SUPER) > 0)
				status = GLFW_PRESS;
			break;
		default:
			status = glfwGetKey(window, keycode);
			break;
		}
		
		return status == GLFW_PRESS;
	}
	bool OpenGLInput::GetMouseButtonState(int button)
	{
		GLFWwindow* window;
		try
		{
			window = std::any_cast<GLFWwindow*>(Application::GetWindow()->Get());
		}
		catch (std::bad_any_cast exec)
		{
			ASSERT(0, "Invalid Window Cast!");
		}

		int status = glfwGetMouseButton(window, button);
		return status == GLFW_PRESS;
	}

	glm::vec2 OpenGLInput::MousePositionRetriever()
	{
		GLFWwindow* window;
		try
		{
			window = std::any_cast<GLFWwindow*>(Application::GetWindow()->Get());
		}
		catch (std::bad_any_cast exec)
		{
			ASSERT(0, "Invalid Window Cast!");
		}
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return glm::vec2((float)x, (float)y);
	}
}
