#include "AnimationData.h"

const AnimationData animationDataArray[NUMBER_ANIMATIONDATA] =
{
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_STAND_RIGHT, 364, 108, 48, 100, 9, 4, true),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_STAND_LEFT, 0, 108, 48, 100, 9, 4, false),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_KICK_LEFT, 12, 18, 48, 145, 8, 7, true),
	AnimationData("../Ressources/Characters/MK/Sub-ZERO/sub-zero.png", SUB_ZERO_STAND_RIGHT, 34, 19, 38, 120, 9, 64, true),
	AnimationData("../Ressources/Characters/MK/Sub-ZERO/sub-zero.png", SUB_ZERO_STAND_LEFT, 40, 8, 418, 910, 92, 43, false),
}

AnimationData::AnimationData()
{
	this->fileName = "";
	this->animationName = 0;
	this->posX = 0;
	this->posY = 0;
	this->spriteWidth = 0;
	this->spriteHeight = 0;
	this->framerate = 0;
	this->spriteNb = 0;
	this->animationLoop = false;
}

AnimationData::AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop)
{
	this->fileName = fileName;
	this->animationName = animationName;
	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;
	this->animationLoop = animationLoop;
}

AnimationData::~AnimationData(void)
{
}

string AnimationData::getFileName() const
{
	return this->fileName;
}

int AnimationData::getAnimationName() const
{
	return this->animationName;
}

int AnimationData::getPosX() const
{
	return this->posX;
}

int AnimationData::getPosY() const
{
	return this->posY;
}

int AnimationData::getSpriteWidth() const
{
	return this->spriteWidth;
}

int AnimationData::getSpriteHeight() const
{
	return this->spriteHeight;
}

int AnimationData::getFramerate() const
{
	return this->framerate;
}

int AnimationData::getSpriteNb() const
{
	return this->spriteNb;
}

bool AnimationData::getAnimationLoop() const
{
	return this->animationLoop;
}
