#ifndef _TIMER_H
#define _TIMER_H



class Timer
{
private:
	bool reverseTime;
	int timerLimit;
	int timerFrame;

public:
	Timer();
	Timer(bool reverseTime, int timerLimit);
	~Timer(void);
	void updateTimer();
	int getTime();
};

#endif