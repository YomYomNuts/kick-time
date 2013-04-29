#include "SoundLine.h"


SoundLine::SoundLine(void)
{
	this->fileName = "";
	this->soundID = "";
	this->isMusic = false;
	this->isLoop = false;
}

SoundLine::SoundLine(string fileName, string soundID, bool isMusic, bool isLoop)
{
	this->fileName = fileName;
	this->soundID = soundID;
	this->isMusic = isMusic;
	this->isLoop = isLoop;
}

SoundLine::~SoundLine(void)
{
}

string SoundLine::getFileName()
{
	return this->fileName;
}

string SoundLine::getSoundID()
{
	return this->soundID;
}

bool SoundLine::getIsMusic()
{
	return this->isMusic;
}

bool SoundLine::getIsLoop()
{
	return this->isLoop;
}
