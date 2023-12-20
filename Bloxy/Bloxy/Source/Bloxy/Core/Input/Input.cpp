#include "pchBloxy.h"
#include "Input.h"

#include "Events.h"
#include "RendererAPI/OpenGL/RendererAPI.h"
#include "RendererAPI/OpenGL/OpenGLInput.h"


namespace Bloxy
{
	Input* Input::s_Instance = nullptr;
	
	Input::Input()
		:m_CharCount(0), m_Scroll(0.0f)
	{
		for (uint8_t& key : m_Keys)
			key = BLOXY_NONE;
		for (uint8_t& button : m_MouseButtons)
			button = BLOXY_NONE;
		m_Chars[0] = '\0';
	}

	void Input::Init()
	{
		BLOXY_ASSERT(!s_Instance, "Input Engine already initialized!");
		
		switch (RendererAPI::GetBackend())
		{
		case RendererAPI::Backend::OpenGL:
			s_Instance = new (std::nothrow) OpenGLInput();
		}
		BLOXY_ASSERT(s_Instance, "Failed to initialize Input Engine!");
	}

	void Input::Destroy()
	{
		delete s_Instance;
	}

	Input* Input::Get()
	{
		return s_Instance;
	}

	bool Input::GetKey(int keycode)
	{
		s_Instance->ValidateKey(keycode);
		return s_Instance->GetKeyState(keycode);
	}

	bool Input::GetKeyDown(int keycode)
	{
		s_Instance->ValidateKey(keycode);
		return s_Instance->m_Keys[keycode] == BLOXY_PRESS;
	}

	bool Input::GetKeyUp(int keycode)
	{
		s_Instance->ValidateKey(keycode);
		return s_Instance->m_Keys[keycode] == BLOXY_RELEASE;
	}

	std::string Input::GetString()
	{
		return s_Instance->m_Chars.data();
	}

	bool Input::GetMouseButton(int button)
	{
		s_Instance->ValidateMouseButton(button);
		return s_Instance->GetMouseButtonState(button);
	}

	bool Input::GetMouseButtonDown(int button)
	{
		s_Instance->ValidateMouseButton(button);
		return s_Instance->m_MouseButtons[button] == BLOXY_PRESS;
	}

	bool Input::GetMouseButtonUp(int button)
	{
		s_Instance->ValidateMouseButton(button);
		return s_Instance->m_MouseButtons[button] == BLOXY_RELEASE;
	}

	float Input::GetScroll()
	{
		return s_Instance->m_Scroll;
	}

	Vector2 Input::GetMousePosition()
	{
		return s_Instance->MousePositionRetriever();
	}

	float Input::GetMouseX()
	{
		return s_Instance->GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return s_Instance->GetMousePosition().y;
	}

	void Input::ValidateKey(int keycode) const
	{
		BLOXY_ASSERT(BLOXY_KEY_FIRST <= keycode && keycode <= BLOXY_KEY_LAST,
			"Invalid KeyCode '{0}'", keycode);
	}

	void Input::ValidateMouseButton(int button) const
	{
		BLOXY_ASSERT(BLOXY_MOUSE_BUTTON_FIRST <= button && button <= BLOXY_MOUSE_BUTTON_LAST,
			"Invalid Mouse Button '{0}'", button);
	}

	bool Input::GetKeyState(int keycode)
	{
		return false;
	}

	bool Input::GetMouseButtonState(int button)
	{
		return false;
	}

	void Input::AttachEvent(const Event& event)
	{
		switch (event.GetType())
		{
			case EventType::KeyPress:
			{
				KeyPressEvent ke = Event::Cast<KeyPressEvent>(event);
				m_Keys[ke.GetKey().Value] = BLOXY_PRESS;

				switch (ke.GetKey().Value)
				{
				case BLOXY_KEY_LEFT_SHIFT:
				case BLOXY_KEY_RIGHT_SHIFT:
					m_Keys[BLOXY_KEY_SHIFT] = BLOXY_PRESS;
					break;
				case BLOXY_KEY_LEFT_ALT:
				case BLOXY_KEY_RIGHT_ALT:
					m_Keys[BLOXY_KEY_ALT] = BLOXY_PRESS;
					break;
				case BLOXY_KEY_LEFT_CONTROL:
				case BLOXY_KEY_RIGHT_CONTROL:
					m_Keys[BLOXY_KEY_CONTROL] = BLOXY_PRESS;
					break;
				case BLOXY_KEY_LEFT_SUPER:
				case BLOXY_KEY_RIGHT_SUPER:
					m_Keys[BLOXY_KEY_SUPER] = BLOXY_PRESS;
					break;
				}
			} break;
			case EventType::KeyRelease:
			{
				KeyReleaseEvent ke = Event::Cast<KeyReleaseEvent>(event);
				m_Keys[ke.GetKey().Value] = BLOXY_RELEASE;

				switch (ke.GetKey().Value)
				{
				case BLOXY_KEY_LEFT_SHIFT:
				case BLOXY_KEY_RIGHT_SHIFT:
					m_Keys[BLOXY_KEY_SHIFT] = BLOXY_RELEASE;
					break;
				case BLOXY_KEY_LEFT_ALT:
				case BLOXY_KEY_RIGHT_ALT:
					m_Keys[BLOXY_KEY_ALT] = BLOXY_RELEASE;
					break;
				case BLOXY_KEY_LEFT_CONTROL:
				case BLOXY_KEY_RIGHT_CONTROL:
					m_Keys[BLOXY_KEY_CONTROL] = BLOXY_RELEASE;
					break;
				case BLOXY_KEY_LEFT_SUPER:
				case BLOXY_KEY_RIGHT_SUPER:
					m_Keys[BLOXY_KEY_SUPER] = BLOXY_RELEASE;
					break;
				}
			} break;
			case EventType::Char:
			{
				CharEvent ce = Event::Cast<CharEvent>(event);
				if (m_CharCount >= MAX_INPUT_STRING)
				{
					BLOXY_WARNING("Input String size was exceeded!");
				}
				else
				{
					m_Chars[m_CharCount++] = ce.GetChar();
					m_Chars[m_CharCount] = '\0';
				}
			} break;
			case EventType::MouseButtonPress:
			{
				MouseButtonPressEvent me = Event::Cast<MouseButtonPressEvent>(event);
				m_MouseButtons[me.GetButton()] = BLOXY_PRESS;
			} break;
			case EventType::MouseButtonRelease:
			{
				MouseButtonReleaseEvent me = Event::Cast<MouseButtonReleaseEvent>(event);
				m_MouseButtons[me.GetButton()] = BLOXY_RELEASE;
			} break;
			case EventType::Wheel:
			{
				WheelEvent we = Event::Cast<WheelEvent>(event);
				m_Scroll = we.GetValue();
			} break;
		}
	}

	void Input::Reset()
	{
		for (int i = 0; i < m_Keys.size(); i++)
		{
			m_Keys[i] = BLOXY_NONE;
		}

		for (int i = 0; i < m_MouseButtons.size(); i++)
		{
			m_MouseButtons[i] = BLOXY_NONE;
		}

		m_Chars[0] = '\0';
		m_CharCount = 0;

		m_Scroll = 0.0f;
	}
}