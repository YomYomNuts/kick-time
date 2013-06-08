#include "Timer.h"
#include "GameManager_Defines.h"


Timer::Timer(void)
{
	this->reverseTime = false;
	this->timerStart = 0;
	this->timerFrame = 0;
}

Timer::Timer(bool reverseTime, int timerStart)
{
	this->reverseTime = reverseTime;
	this->timerStart = timerStart;
	this->timerFrame = 0;
}

Timer::~Timer(void)
{
}

void Timer::updateTimer()
{
	++this->timerFrame;
}

int Timer::getTime()
{
	if (this->reverseTime)
		return this->timerStart - (int)this->timerFrame / NUMBER_FRAME_PER_SECOND;
	else
		return this->timerStart + (int)this->timerFrame / NUMBER_FRAME_PER_SECOND;
}
