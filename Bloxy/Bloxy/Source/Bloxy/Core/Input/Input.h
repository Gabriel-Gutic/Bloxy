#pragma once
#include "Event.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

#include <glm/glm.hpp>

#define BLOXY_NONE 0
#define BLOXY_PRESS 1
#define BLOXY_RELEASE 2

#define MAX_INPUT_STRING 15


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
		static std::string GetString();

		static bool GetMouseButton(int button);
		static bool GetMouseButtonDown(int button);
		static bool GetMouseButtonUp(int button);
		static float GetScroll();
		static Vector2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	public:
		void AttachEvent(const Event& event);
		void Reset();
	protected:
		void ValidateKey(int keycode) const;
		void ValidateMouseButton(int button) const;
		virtual bool GetKeyState(int keycode);
		virtual bool GetMouseButtonState(int button);
		virtual glm::vec2 MousePositionRetriever() = 0;
	protected:
		std::array<uint8_t, BLOXY_KEY_LAST + 1> m_Keys;
		std::array<uint8_t, BLOXY_MOUSE_BUTTON_LAST + 1> m_MouseButtons;
		std::array<char, MAX_INPUT_STRING + 1> m_Chars;
		uint32_t m_CharCount;

		float m_Scroll;

		static Input* s_Instance;
	};
}