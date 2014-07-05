#include "LevelManager.h"
#include "LevelData.h"

LevelManager::LevelManager(void)
{
	this->activeLevel = NULL;
}

LevelManager::~LevelManager(void)
{
    if (this->activeLevel != NULL)
        delete this->activeLevel;
}

void LevelManager::initializeLevelManager()
{
    if (this->activeLevel != NULL)
        delete this->activeLevel;
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

void LevelManager::unloadActiveLevel()
{
    if (this->activeLevel != NULL)
        delete this->activeLevel;
	this->activeLevel = NULL;
}
