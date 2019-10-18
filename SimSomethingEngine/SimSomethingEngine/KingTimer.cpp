#include "KingTimer.h"

using namespace std::chrono;

KingTimer::KingTimer() noexcept
{
	last = steady_clock::now();
}

float KingTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float KingTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
