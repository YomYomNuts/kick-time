#ifndef _LEVEL_H
#define _LEVEL_H

#include "Position.h"
#include "LevelData.h"
#include "Timer.h"
#include "AnimationLevel.h"
#include "Character.h"

#include <SFML/Graphics.hpp>


// State level
enum LevelState {
	STATE_LEVEL_START_ROUND,
	STATE_LEVEL_ROUND,
	STATE_LEVEL_END_ROUND,
	STATE_LEVEL_END_MATCH
};

class Level
{
private:
	Position * positionDisplay;
	const LevelData * levelData;
	sf::Sprite * spriteLevel;
	LevelState levelState;
	Timer * timer;
	bool endOfLevelReached;
	vector<AnimationLevel*> * listAnimation;
	vector<sf::Sprite*> * listSpriteLevelAnim;
	AnimationLevel * anim;

public:
	Level(void);
	Level(const LevelData * levelData);
	~Level(void);
	void updateLevel();
	void renderLevel();
	const LevelData* getLevelData();
	int getTimer();
	Position * getPosition();
	void setEndOfLevelReachedState(bool endOfScreen);
	bool getEndOfLevelReachedState();
	sf::Sprite * getSpriteLevel();
	void setPosX(double posX);
	double getPosX();
	LevelState getLevelState();
	void nextStateLevel(Character * characterWin);
};

#endif
