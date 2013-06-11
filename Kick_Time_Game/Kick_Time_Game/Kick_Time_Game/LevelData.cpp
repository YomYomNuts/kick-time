#include "LevelData.h"

const LevelData levelDataArray[NUMBER_LEVELDATA] =
{
	LevelData("../Ressources/Levels/MK/TheTower.png", "THE_TOWER", LEVEL_0, 290),
	LevelData("../Ressources/Levels/MK/The_Armory.png", "THE_ARMORY", LEVEL_1, 290),
};

LevelData::LevelData()
{
	this->fileName = "";
	this->levelName = "";
	this->levelID = 0;
	this->posYCharacter = 0;
}

LevelData::LevelData(string fileName, string levelName, int levelID, int posYCharacter)
{
	this->fileName = fileName;
	this->levelName = levelName;
	this->levelID = levelID;
	this->posYCharacter = posYCharacter;
}

LevelData::~LevelData(void)
{
}

string LevelData::getFileName() const
{
	return this->fileName;
}

string LevelData::getLevelName() const
{
	return this->levelName;
}

int LevelData::getLevelID() const
{
	return this->levelID;
}

int LevelData::getPosYCharacter() const
{
	return this->posYCharacter;
}
