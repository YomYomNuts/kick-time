#ifndef _LEVEL_H
#define _LEVEL_H

#include "Position.h"

class Level
{
private:
	Position positionDisplay;
public:
	Level(void);
	~Level(void);
	void RenderLevel();
};

#endif