#include "SoundData.h"

const SoundData soundDataArray[NUMBER_SOUNDDATA] =
{
	SoundData("../Ressources/Sounds/19 Triangle X2.wav", SOUND_LEVEL_SCORPION, true, true),
};

SoundData::SoundData()
{
	this->fileName = "";
	this->soundID = 0;
	this->isMusic = false;
	this->isLoop = false;
}

SoundData::SoundData(string fileName, int soundID, bool isMusic, bool isLoop)
{
	this->fileName = fileName;
	this->soundID = soundID;
	this->isMusic = isMusic;
	this->isLoop = isLoop;
}

SoundData::~SoundData(void)
{
}

string SoundData::getFileName() const
{
	return this->fileName;
}

int SoundData::getSoundID() const
{
	return this->soundID;
}

bool SoundData::getIsMusic() const
{
	return this->isMusic;
}

bool SoundData::getIsLoop() const
{
	return this->isLoop;
}
