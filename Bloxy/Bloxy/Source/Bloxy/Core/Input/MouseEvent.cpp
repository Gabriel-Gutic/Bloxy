#include "pchBloxy.h"
#include "MouseEvent.h"

#include "MouseCodes.h"


namespace Bloxy
{
	const std::unordered_map<int, std::string> MouseButtonEvent::s_ButtonNames =
	{
		{ BLOXY_MOUSE_BUTTON_LEFT, "Left Button" },
		{ BLOXY_MOUSE_BUTTON_RIGHT, "Right Button" },
		{ BLOXY_MOUSE_BUTTON_MIDDLE, "Middle Button" },
	};

	std::string MouseButtonEvent::ToString() const
	{
		std::stringstream ss;
		ss << this->GetName() << ": ";
		if (s_ButtonNames.find(m_Button) == s_ButtonNames.end())
			ss << m_Button + 1;
		else ss << s_ButtonNames.at(m_Button);
		return ss.str();
	}

	std::string WheelEvent::ToString() const
	{
		std::stringstream ss;
		ss << this->GetName() << ": " << m_Value;
		return ss.str();
	}
}