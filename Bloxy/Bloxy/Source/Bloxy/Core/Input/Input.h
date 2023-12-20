#pragma once
#include "Event.h"
#include "KeyCodes.h"
#include "MouseCodes.h"


#define BLOXY_NONE 0
#define BLOXY_PRESS 1
#define BLOXY_REPEAT 2
#define BLOXY_RELEASE 3


namespace Bloxy
{
	class Input
	{
	protected:
		Input();
	public:
		Input(const Input& other) = delete;
		~Input() = default;

		static void Init();
		static void Destroy();

		static Input* Get();

		static bool GetKey(int keycode);
		static bool GetKeyDown(int keycode);
		static bool GetKeyUp(int keycode);
	public:
		void AttachEvent(const Event& event);
		void Reset();
	protected:
		void ValidateKey(int keycode) const;
		virtual bool GetKeyStatus(int keycode);
	protected:
		std::array<uint8_t, BLOXY_KEY_LAST + 1> m_Keys;
		std::array<uint8_t, BLOXY_MOUSE_BUTTON_LAST + 1> m_MouseButtons;
	
		static Input* s_Instance;
	};
}