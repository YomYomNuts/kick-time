#ifndef _MATCH_H
#define _MATCH_H

#include "Timer.h"

class Match
{
private:
	Timer * time;

public:
	Match(void);
	~Match(void);
	void updateMatch();
	int getTime();
};

#endif