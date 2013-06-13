#include "Level.h"
#include "GameManager.h"

#include <iostream>

Level::Level(void)
{
	this->positionDisplay = new Position();
	this->levelData = new LevelData();
	this->spriteLevel = new sf::Sprite();
	this->time = new Timer(true, 99);
	this->endOfLevelReached = false;
}

Level::Level(const LevelData * levelData)
{
	this->levelData = levelData;
	this->spriteLevel = new sf::Sprite();
	this->spriteLevel->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->levelData->getFileName()));
	this->positionDisplay = new Position((double)SCREEN_SIZE_WIDTH / 2 - this->spriteLevel->getTexture()->getSize().x / 2, (double)SCREEN_SIZE_HEIGHT - this->spriteLevel->getTexture()->getSize().y);
	this->time = new Timer(true, 99);
	this->endOfLevelReached = false;

	for(int i= 0; i < this->levelData->getLevelAnimationData().size(); ++i)
	{
		//listAnimation.push_back(
	}
}

Level::~Level(void)
{
	delete this->positionDisplay;
	delete this->spriteLevel;
	delete this->time;
}

void Level::updateLevel()
{
	if (this->time != NULL)
		this->time->updateTimer();
}

void Level::renderLevel()
{
	//Draw
	this->spriteLevel->setPosition((float)this->positionDisplay->getX(), (float)this->positionDisplay->getY());
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteLevel);
}

int Level::getTime()
{
	if (this->time != NULL)
		return this->time->getTime();
	return 0;
}

const LevelData * Level::getLevelData()
{
	return this->levelData;
}

Position * Level::getPosition()
{
	return positionDisplay;
}

void Level::setEndOfLevelReachedState(bool endOfScreen)
{
	this->endOfLevelReached = endOfScreen;
}

bool Level::getEndOfLevelReachedState()
{
	return this->endOfLevelReached;
}

sf::Sprite * Level::getSpriteLevel()
{
	return spriteLevel;
}

void Level::setPosX(double posX)
{
	double levelWidth = this->spriteLevel->getTexture()->getSize().x;
	double posXlevel = this->positionDisplay->getX();

	this->positionDisplay->setX(posX);

	if(posX >= 0)
	{
		this->positionDisplay->setX(0);
		this->endOfLevelReached = true;
	}
	else if(posX + levelWidth <= SCREEN_SIZE_WIDTH)
	{
		this->positionDisplay->setX(SCREEN_SIZE_WIDTH- levelWidth);
		this->endOfLevelReached = true;
	}
	else
		this->endOfLevelReached = false;
}