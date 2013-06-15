#ifndef _LEVELMANAGER_H
#define _LEVELMANAGER_H

#include "Level.h"

#include <vector>

using namespace std;

class LevelManager
{
private:
	vector<Level> * listLevels;
	Level * activeLevel;

public:
	LevelManager(void);
	~LevelManager(void);
	void initializeLevelManager();
	void updateLevelManager();
	void renderLevelManager();
	Level* getActiveLevel();
	void setActiveLevel(int indexLevel);
};

#endif