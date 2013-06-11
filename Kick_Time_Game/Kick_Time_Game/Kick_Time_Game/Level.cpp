#include "Level.h"
#include "GameManager.h"

#include <iostream>

Level::Level(void)
{
	this->positionDisplay = new Position();
	this->levelData = new LevelData();
	this->spriteLevel = new sf::Sprite();
	this->time = new Timer(true, 99);
}

Level::Level(const LevelData * levelData)
{
	this->levelData = levelData;
	this->spriteLevel = new sf::Sprite();
	this->spriteLevel->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->levelData->getFileName()));
	this->positionDisplay = new Position((double)SCREEN_SIZE_WIDTH / 2 - this->spriteLevel->getTexture()->getSize().x / 2, 0);
	this->time = new Timer(true, 99);
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