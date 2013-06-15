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
}

void LevelManager::updateLevelManager()
{
	if (this->activeLevel != NULL)
		this->activeLevel->updateLevel();
}

void LevelManager::renderLevelManager()
{
	if (this->activeLevel != NULL)
		this->activeLevel->renderLevel();
}

Level* LevelManager::getActiveLevel()
{
	return this->activeLevel;
}

void LevelManager::setActiveLevel(int indexLevel)
{
	this->activeLevel = new Level(&levelDataArray[indexLevel]);
}