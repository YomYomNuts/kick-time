#include "Level.h"
#include "GameManager.h"

#include <iostream>

Level::Level(void)
{
	this->positionDisplay = new Position();
	this->levelData = new LevelData();
	this->spriteLevel = new sf::Sprite();
}

Level::Level(const LevelData * levelData)
{
	this->positionDisplay = new Position();
	this->levelData = levelData;

    // Load the sprite image from a levelData
	sf::Texture * textureLevel = new sf::Texture();
	if (!textureLevel->loadFromFile(this->levelData->getFileName()))
	{
		cerr << "Error in loading of the texture of level " << this->levelData->getFileName() << "!" << std::endl;
	}
	else
	{
		this->positionDisplay->setX(SCREEN_SIZE_WIDTH/2 - textureLevel->getSize().x/2);
		this->spriteLevel = new sf::Sprite(*textureLevel);
	}
}

Level::~Level(void)
{
	delete this->positionDisplay;
	delete this->spriteLevel;
}

void Level::renderLevel()
{
	//Draw
	spriteLevel->setPosition((float)this->positionDisplay->getX(), (float)this->positionDisplay->getY());
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*spriteLevel);
}