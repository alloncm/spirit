#include "FrameTime.h"

FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

float FrameTimer::Mark()
{
	const steady_clock::time_point old = last;
	last = steady_clock::now();
	const duration<float> TimeFrame = last - old;
	return TimeFrame.count();
}
