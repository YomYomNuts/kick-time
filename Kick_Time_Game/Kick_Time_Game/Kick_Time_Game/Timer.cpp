#include "Timer.h"
#include "GameManager_Defines.h"


Timer::Timer(void)
{
	this->reverseTime = false;
	this->timerLimit = 0;
	this->timerFrame = 0;
}

Timer::Timer(bool reverseTime, int timerLimit)
{
	this->reverseTime = reverseTime;
	this->timerLimit = timerLimit;
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
	{
		int time = this->timerLimit - (int)this->timerFrame / NUMBER_FRAME_PER_SECOND;
		return time < 0 ? 0 : time ;
	}
	else
	{
		int time = (int)this->timerFrame / NUMBER_FRAME_PER_SECOND;
		return time > this->timerLimit ? this->timerLimit : time ;
	}
}
