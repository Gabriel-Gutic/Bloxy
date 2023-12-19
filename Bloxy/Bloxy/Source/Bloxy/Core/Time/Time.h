#pragma once


namespace Bloxy
{
	class Time
	{
		Time();
	public:
		Time(const Time& other) = delete;
		~Time() = default;

		static void Init();
		static void Destroy();

		static void Reset();

		static void CountFPS();

		static float GetTime();
		static int GetFPS();
		static float GetDeltaTime();
	private:
		std::shared_ptr<Timer> m_Timer;
		float m_LastTime;
		int m_Frames;
		int m_FPS;
		float m_DeltaTime;

		static Time* s_Instance;
	};
}