#include "LevelLine.h"


LevelLine::LevelLine(void)
{
	this->fileName = "";
	this->levelID = "";
	this->levelName = "";
	this->posX = 0;
	this->posY = 0;
}

LevelLine::LevelLine(char * fileName, char * levelID, char * levelName, int posX, int posY)
{
	this->fileName = fileName;
	this->levelID = levelID;
	this->levelName = levelName;
	this->posX = posX;
	this->posY = posY;
}

LevelLine::~LevelLine(void)
{
	delete[] this->fileName;
	delete[] this->levelID;
	delete[] this->levelName;
}

char* LevelLine::getFileName()
{
	return this->fileName;
}

char* LevelLine::getLevelID()
{
	return this->levelID;
}

char* LevelLine::getLevelName()
{
	return this->levelName;
}

int LevelLine::getPosX()
{
	return this->posX;
}

int LevelLine::getPosY()
{
	return this->posY;
}