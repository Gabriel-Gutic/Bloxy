#include "pchBloxy.h"
#include "Time.h"


namespace Bloxy
{
	Time* Time::s_Instance = nullptr;

	Time::Time()
		:m_Timer(nullptr), m_FPS(60), m_Frames(0), m_DeltaTime(1.0f / 60.0f), m_LastTime(0.0f)
	{
		m_Timer = std::make_shared<Timer>();
	}

	void Time::Init()
	{
		BLOXY_ASSERT(!s_Instance, "Time Engine already initialized!");
		s_Instance = new (std::nothrow) Time();
		BLOXY_ASSERT(s_Instance, "Failed to initialize Time Engine!");
	}

	void Time::Destroy()
	{
		delete s_Instance;
	}

	void Time::Reset()
	{
		auto& ins = s_Instance;
		ins->m_FPS = 60.0f;
		ins->m_Frames = 0;
		ins->m_DeltaTime = 1.0f / 60.0f;
		ins->m_Timer->Reset();
	}

	void Time::CountFPS()
	{
		auto& ins = s_Instance;

		ins->m_Frames++;

		float time = GetTime();
		float delta = time - ins->m_LastTime;
		if (delta >= 1.0f)
		{
			ins->m_FPS = (int)((float)ins->m_Frames / delta);
			ins->m_DeltaTime = 1.0f / ins->m_FPS;

			ins->m_Frames = 0;
			ins->m_LastTime = time;
		}
	}

	float Time::GetTime()
	{
		return s_Instance->m_Timer->GetSeconds(4);
	}

	int Time::GetFPS()
	{
		return s_Instance->m_FPS;;
	}

	float Time::GetDeltaTime()
	{
		return s_Instance->m_DeltaTime;
	}
}