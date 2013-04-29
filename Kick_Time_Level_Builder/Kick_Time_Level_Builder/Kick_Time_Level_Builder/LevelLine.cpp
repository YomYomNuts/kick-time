#include "LevelLine.h"

#include <iostream>

using namespace std;

LevelLine::LevelLine(void)
{
	this->fileName = "";
	this->levelName = "";
	this->levelID = "";
	this->posYCharacter = 0;
}

LevelLine::LevelLine(string fileName, string levelID, string levelName, int posYCharacter)
{
	this->fileName = fileName;
	this->levelName = levelName;
	this->levelID = levelID;
	this->posYCharacter = posYCharacter;
}

LevelLine::~LevelLine(void)
{
}

string LevelLine::getFileName()
{
	return this->fileName;
}

string LevelLine::getLevelName()
{
	return this->levelName;
}

string LevelLine::getLevelID()
{
	return this->levelID;
}

int LevelLine::getPosYCharacter()
{
	return this->posYCharacter;
}