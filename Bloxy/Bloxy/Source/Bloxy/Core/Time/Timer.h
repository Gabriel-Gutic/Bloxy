#pragma once


namespace Bloxy
{
	class Timer
	{
	public:
		Timer();
		~Timer();

		void Reset();

		unsigned long long GetMicroseconds() const;
		float GetMilliseconds(unsigned int precision = 2) const;
		float GetSeconds(unsigned int precision = 2) const;
		std::string MicrosecondsToString() const;
		std::string MillisecondsToString(unsigned int precision = 2) const;
		std::string SecondsToString(unsigned int precision = 2) const;
		
		static void Wait(unsigned long long ms);
	private:
		bool isStopped;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};
}

#define SLEEP(ms) Tomato::Timer::Wait(ms)
