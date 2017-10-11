#pragma once
#include<chrono>
using namespace std::chrono;
class FrameTimer
{
public:
	FrameTimer();
	float Mark();
private:
	steady_clock::time_point last;
};