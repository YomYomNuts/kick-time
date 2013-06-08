#ifndef _MATCHMANAGER_H
#define _MATCHMANAGER_H

#include "Match.h"

class MatchManager
{
private:
	Match * activeMatch;

public:
	MatchManager(void);
	~MatchManager(void);
	void initializeMatchManager();
	void updateMatchManager();
	void setMatch(Match * match);
	Match* getActiveMatch();
};

#endif