#include "LevelData.h"

using namespace std;

const LevelData levelDataArray[NUMBER_LEVELDATA] =
{
	LevelData("../Ressources/Levels/MK/TheTower.png", "THE_TOWER", LEVEL_0, 290),
	LevelData("../Ressources/Levels/MK/The_Armory.png", "THE_ARMORY", LEVEL_1, 290),
};

const map<int, vector<LevelAnimationData>> levelAnimDataArray = create_map<int, vector<LevelAnimationData>>
	(LEVEL_1, create_vector<LevelAnimationData>
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",0,0,0,11,87,3,13,true,0,0,0,678,222))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",1,170,0,11,87,3,13,true,0,0,0,112,222))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",2,630,0,9,18,10,2,true,0,0,0,298,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",3,601,0,9,18,10,2,true,0,0,0,306,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",4,322,0,116,28,10,2,true,0,0,0,187,231))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",5,630,0,9,18,10,2,true,0,0,0,488,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",6,601,0,9,18,10,2,true,0,0,0,496,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",7,322,38,116,28,10,2,true,0,0,0,498,231))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",8,558,0,19,28,10,2,true,0,0,0,123,231))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",9,558,0,19,28,10,2,true,0,0,0,318,231))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",10,558,0,19,28,10,2,true,0,0,0,464,231))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",11,558,0,19,28,10,2,true,0,0,0,659,231))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",12,601,0,9,18,10,2,true,0,0,0,146,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",13,630,0,9,18,10,2,true,0,0,0,154,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",14,601,0,9,18,10,2,true,0,0,0,162,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",15,630,0,9,18,10,2,true,0,0,0,170,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",16,601,0,9,18,10,2,true,0,0,0,178,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",17,630,0,9,18,10,2,true,0,0,0,361,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",18,601,0,9,18,10,2,true,0,0,0,369,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",19,630,0,9,18,10,2,true,0,0,0,377,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",20,601,0,9,18,10,2,true,0,0,0,385,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",21,630,0,9,18,10,2,true,0,0,0,393,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",22,601,0,9,18,10,2,true,0,0,0,401,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",23,630,0,9,18,10,2,true,0,0,0,409,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",24,601,0,9,18,10,2,true,0,0,0,417,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",25,630,0,9,18,10,2,true,0,0,0,425,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",26,601,0,9,18,10,2,true,0,0,0,433,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",27,601,0,9,18,10,2,true,0,0,0,614,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",28,630,0,9,18,10,2,true,0,0,0,622,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",29,601,0,9,18,10,2,true,0,0,0,630,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",30,630,0,9,18,10,2,true,0,0,0,638,221))
		(LevelAnimationData("../Ressources/Levels/MK/The_Armory.png",31,601,0,9,18,10,2,true,0,0,0,646,221))
		);

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

const vector<LevelAnimationData> LevelData::getLevelAnimationData() const
{
	return levelAnimDataArray.at(this->levelID);
}
