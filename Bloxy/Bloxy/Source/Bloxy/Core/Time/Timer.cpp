#include "pchBloxy.h"
#include "Timer.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


namespace Bloxy
{
	Timer::Timer()
		:isStopped(false)
	{
		this->Reset();
	}

	Timer::~Timer()
	{
	}

	void Timer::Reset()
	{
		m_Start = std::chrono::high_resolution_clock::now();
	}

	void Timer::Wait(unsigned long long ms)
	{
		Sleep((unsigned long)ms);
	}

	unsigned long long Timer::GetMicroseconds() const
	{
		double seconds = GetSeconds(6);
		return (unsigned long long)(seconds * 1000000);
	}

	float Timer::GetMilliseconds(unsigned int precision) const
	{
		float seconds = GetSeconds(precision + 3);
		return seconds * 1000;
	}

	float Timer::GetSeconds(unsigned int precision) const
	{
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> duration = end - m_Start;

		double power = std::pow(10, precision);
		return (duration.count() * power) / power;
	}

	std::string Timer::MicrosecondsToString() const
	{
		return std::to_string(GetMicroseconds()) + (char)230 + "s";
	}

	std::string Timer::MillisecondsToString(unsigned int precision) const
	{
		return std::to_string(GetMilliseconds(precision)) + "ms";
	}

	std::string Timer::SecondsToString(unsigned int precision) const
	{
		return std::to_string(GetSeconds(precision)) + "s";
	}
}