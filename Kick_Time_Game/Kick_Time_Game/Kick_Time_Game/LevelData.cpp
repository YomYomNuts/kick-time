#include "LevelData.h"

const LevelData levelDataArray[NUMBER_LEVELDATA] =
{
	LevelData("../Ressources/Levels/MK/warriorshrine2.png", "WARRIOR_SHRINE", LEVEL_0, 195),
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
