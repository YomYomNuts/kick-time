#ifndef _LEVEL_H
#define _LEVEL_H

#include "Position.h"
#include "LevelData.h"
#include "Timer.h"

#include <SFML/Graphics.hpp>

class Level
{
private:
	Position * positionDisplay;
	const LevelData * levelData;
	sf::Sprite * spriteLevel;
	Timer * time;
	bool endOfLevelReached;

public:
	Level(void);
	Level(const LevelData * levelData);
	~Level(void);
	void updateLevel();
	void renderLevel();
	const LevelData* getLevelData();
	int getTime();
	Position * getPosition();
	void setEndOfLevelReachedState(bool endOfScreen);
	bool getEndOfLevelReachedState();
	sf::Sprite * getSpriteLevel();
	void setPosX(double posX);
	double getPosX();
};

#endif