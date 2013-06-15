#include "AnimationLine.h"

AnimationLine::AnimationLine()
{
	this->levelNumber = 0;
	this->fileName = "";
	this->animationNumber = 0;
	this->posX = 0;
	this->posY = 0;
	this->spriteWidth = 0;
	this->spriteHeight = 0;
	this->framerate = 0;
	this->spriteNb = 0;
	this->animationLoop = false;
	this->posXAnim = 0;
	this->posYAnim = 0;
}

AnimationLine::AnimationLine(int levelNumber, string fileName, int animationNumber, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int posXAnim,int posYAnim)
{
	this->levelNumber = levelNumber;
	this->fileName = fileName;
	this->animationNumber = animationNumber;
	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;
	this->animationLoop = animationLoop;
	this->posXAnim = posXAnim;
	this->posYAnim = posYAnim;
}

AnimationLine::~AnimationLine(void)
{
}

string AnimationLine::getFileName()
{
	return this->fileName;
}

int AnimationLine::getAnimationNumber()
{
	return this->animationNumber;
}

int AnimationLine::getPosX()
{
	return this->posX;
}

int AnimationLine::getPosY()
{
	return this->posY;
}

int AnimationLine::getSpriteWidth()
{
	return this->spriteWidth;
}

int AnimationLine::getSpriteHeight()
{
	return this->spriteHeight;
}

int AnimationLine::getFramerate()
{
	return this->framerate;
}

int AnimationLine::getSpriteNb()
{
	return this->spriteNb;
}

bool AnimationLine::getAnimationLoop()
{
	return this->animationLoop;
}

int AnimationLine::getLevelNumber()
{
	return this->levelNumber;
}

int AnimationLine::getPosXAnim()
{
	return this->posXAnim;
}

int AnimationLine::getPosYAnim()
{
	return this->posYAnim;
}