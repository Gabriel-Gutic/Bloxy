#pragma once


namespace Bloxy
{
	enum class EventType
	{
		KeyPress, KeyRelease, Char,
		MouseButtonPress, MouseButtonRelease, Wheel,
		WindowClose, WindowMinimize, WindowMaximize, WindowResize
	};

	class Event
	{
	public:
		Event(){}
		virtual ~Event(){}

		virtual EventType GetType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const = 0;

		template<typename E>
		static const E Cast(const Event& e);
	};

#define	EVENT_SETUP(type) \
	virtual EventType GetType() const override { return EventType::type; } \
	virtual const char* GetName() const override { return #type; } 
	
	template<typename E>
	inline const E Event::Cast(const Event& e)
	{
		const E* event = dynamic_cast<const E*>(&e);
		BLOXY_ASSERT(event, "Invalid Event Cast!");
		return *event;
	}
}
