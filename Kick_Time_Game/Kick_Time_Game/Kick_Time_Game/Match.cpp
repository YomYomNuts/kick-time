#include "Match.h"


Match::Match(void)
{
	this->time = new Timer(true, 99);
}

Match::~Match(void)
{
}

void Match::updateMatch()
{
	this->time->updateTimer();
}

int Match::getTime()
{
	return this->time->getTime();
}