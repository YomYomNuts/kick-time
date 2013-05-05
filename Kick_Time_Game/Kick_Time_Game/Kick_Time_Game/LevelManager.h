#ifndef _LEVELMANAGER_H
#define _LEVELMANAGER_H

#include "Level.h"

#include <vector>

class LevelManager
{
private:
	std::vector<Level> * listLevels;
	Level * activeLevel;
public:
	LevelManager(void);
	~LevelManager(void);
	void initializeLevelManager();
	void updateLevelManager();
	void renderLevelManager();
};

#endif