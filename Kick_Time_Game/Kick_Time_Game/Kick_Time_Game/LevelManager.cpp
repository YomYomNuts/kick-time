#include "LevelManager.h"
#include "LevelData.h"

LevelManager::LevelManager(void)
{
	this->listLevels = new std::vector<Level>();
	this->activeLevel = NULL;
}

LevelManager::~LevelManager(void)
{
	delete this->listLevels;
	delete this->activeLevel;
}

void LevelManager::initializeLevelManager()
{
	for(int i = 0; i < NUMBER_LEVELDATA; ++i)
	{
		this->listLevels->push_back(*new Level(&levelDataArray[i]));
	}
	if (!this->listLevels->empty())
		this->activeLevel = &this->listLevels->front();
}

void LevelManager::updateLevelManager()
{
	//if (this->activeLevel != NULL)
		//this->activeLevel->updateLevel();
}

void LevelManager::renderLevelManager()
{
	if (this->activeLevel != NULL)
		this->activeLevel->renderLevel();
}