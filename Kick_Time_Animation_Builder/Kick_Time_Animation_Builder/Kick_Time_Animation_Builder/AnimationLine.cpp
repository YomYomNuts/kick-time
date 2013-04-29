#include "AnimationLine.h"

AnimationLine::AnimationLine()
{
       this->fileName = "";
       this->animationName = "";
       this->posX = 0;
       this->posY = 0;
       this->spriteWidth = 0;
       this->spriteHeight = 0;
       this->framerate = 0;
       this->spriteNb = 0;
       this->animationLoop = false;
}

AnimationLine::AnimationLine(string fileName, string animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop)
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

AnimationLine::~AnimationLine(void)
{
}

string AnimationLine::getFileName()
{
	return fileName;
}

string AnimationLine::getAnimationName()
{
	return animationName;
}

int AnimationLine::getPosX()
{
	return posX;
}

int AnimationLine::getPosY()
{
	return posY;
}

int AnimationLine::getSpriteWidth()
{
	return spriteWidth;
}

int AnimationLine::getSpriteHeight()
{
	return spriteHeight;
}

int AnimationLine::getFramerate()
{
	return framerate;
}

int AnimationLine::getSpriteNb()
{
	return spriteNb;
}

bool AnimationLine::getAnimationLoop()
{
	return animationLoop;
}