#include "MatchManager.h"

#include <stdio.h>


MatchManager::MatchManager(void)
{
	this->activeMatch = NULL;
}

MatchManager::~MatchManager(void)
{
	delete this->activeMatch;
}

void MatchManager::initializeMatchManager()
{
}

void MatchManager::updateMatchManager()
{
	if (this->activeMatch != NULL)
		this->activeMatch->updateMatch();
}

void MatchManager::setMatch(Match * match)
{
	this->activeMatch = match;
}

Match* MatchManager::getActiveMatch()
{
	return this->activeMatch;
}