#include "pchBloxy.h"
#include "Input.h"

#include "Events.h"


namespace Bloxy
{
	Input* Input::s_Instance = nullptr;

	void Input::Init()
	{
		BLOXY_ASSERT(!s_Instance, "Input Engine already initialized!");
		s_Instance = new (std::nothrow) Input();
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
		return s_Instance->m_Keys[keycode] == BLOXY_PRESS 
			|| s_Instance->m_Keys[keycode] == BLOXY_REPEAT;
	}

	bool Input::GetKeyDown(int keycode)
	{
		return s_Instance->m_Keys[keycode] == BLOXY_PRESS;
	}

	bool Input::GetKeyUp(int keycode)
	{
		return s_Instance->m_Keys[keycode] == BLOXY_RELEASE;
	}

	void Input::ValidateKey(int keycode) const
	{
		BLOXY_ASSERT(BLOXY_KEY_FIRST <= keycode && keycode <= BLOXY_KEY_LAST,
			"Invalid KeyCode '{0}'", keycode);
	}

	void Input::AttachEvent(const Event& event)
	{
		if (event.GetType() == EventType::KeyPress)
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