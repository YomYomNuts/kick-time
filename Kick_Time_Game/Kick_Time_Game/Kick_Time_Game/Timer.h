#ifndef _TIMER_H
#define _TIMER_H

class Timer
{
private:
	bool reverseTime;
	int timerStart;
	int timerFrame;

public:
	Timer();
	Timer(bool reverseTime, int timerStart);
	~Timer(void);
	void updateTimer();
	int getTime();
};

#endif