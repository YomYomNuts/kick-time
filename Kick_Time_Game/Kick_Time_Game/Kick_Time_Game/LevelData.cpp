#include "LevelData.h"

using namespace std;

const LevelData levelDataArray[NUMBER_LEVELDATA] =
{
	LevelData("../Ressources/Levels/MK/TheTower.png", "THE_TOWER", LEVEL_0, 290),
	LevelData("../Ressources/Levels/MK/The_Armory.png", "THE_ARMORY", LEVEL_1, 290),
};

const map<int,vector<LevelAnimationData>> levelAnimData = create_map<int,vector<LevelAnimationData>>
	(LEVEL_1, create_vector<LevelAnimationData>
		(LevelAnimationData("../Ressources/Levels/MK/TheTower.png",0,0,0,20,87,4,13,true,0,0,0,678,430)));

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

vector<LevelAnimationData> LevelData::getLevelAnimationData() const
{
	return levelAnimData.at(this->levelID);
}
