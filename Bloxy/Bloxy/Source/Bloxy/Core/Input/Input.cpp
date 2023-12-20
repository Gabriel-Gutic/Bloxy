#include "pchBloxy.h"
#include "Input.h"

#include "Events.h"
#include "RendererAPI/OpenGL/RendererAPI.h"
#include "RendererAPI/OpenGL/OpenGLInput.h"


namespace Bloxy
{
	Input* Input::s_Instance = nullptr;
	
	Input::Input()
	{
		for (uint8_t& key : m_Keys)
			key = BLOXY_NONE;
		for (uint8_t& button : m_MouseButtons)
			button = BLOXY_NONE;
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
		return s_Instance->GetKeyStatus(keycode)
			|| s_Instance->m_Keys[keycode] == BLOXY_PRESS 
			|| s_Instance->m_Keys[keycode] == BLOXY_REPEAT;
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

	void Input::ValidateKey(int keycode) const
	{
		BLOXY_ASSERT(BLOXY_KEY_FIRST <= keycode && keycode <= BLOXY_KEY_LAST,
			"Invalid KeyCode '{0}'", keycode);
	}

	bool Input::GetKeyStatus(int keycode)
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
			case EventType::KeyRepeat:
			{
				KeyRepeatEvent ke = Event::Cast<KeyRepeatEvent>(event);
				m_Keys[ke.GetKey().Value] = BLOXY_REPEAT;

				switch (ke.GetKey().Value)
				{
				case BLOXY_KEY_LEFT_SHIFT:
				case BLOXY_KEY_RIGHT_SHIFT:
					m_Keys[BLOXY_KEY_SHIFT] = BLOXY_REPEAT;
					break;
				case BLOXY_KEY_LEFT_ALT:
				case BLOXY_KEY_RIGHT_ALT:
					m_Keys[BLOXY_KEY_ALT] = BLOXY_REPEAT;
					break;
				case BLOXY_KEY_LEFT_CONTROL:
				case BLOXY_KEY_RIGHT_CONTROL:
					m_Keys[BLOXY_KEY_CONTROL] = BLOXY_REPEAT;
					break;
				case BLOXY_KEY_LEFT_SUPER:
				case BLOXY_KEY_RIGHT_SUPER:
					m_Keys[BLOXY_KEY_SUPER] = BLOXY_REPEAT;
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
	}
}