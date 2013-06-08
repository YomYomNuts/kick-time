#ifndef _LEVEL_H
#define _LEVEL_H

#include "Position.h"
#include "LevelData.h"

#include <SFML/Graphics.hpp>

class Level
{
private:
	Position * positionDisplay;
	const LevelData * levelData;
	sf::Sprite * spriteLevel;

public:
	Level(void);
	Level(const LevelData * levelData);
	~Level(void);
	void renderLevel();
};

#endif