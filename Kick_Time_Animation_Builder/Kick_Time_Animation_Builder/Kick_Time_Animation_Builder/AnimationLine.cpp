#include "AnimationLine.h"

#include <iostream>
using namespace std;

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
       this->animationLoop = "";
}

AnimationLine::AnimationLine(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, char* animationLoop)
{
	this->fileName = new char[strlen(fileName)+1];
	strcpy_s(this->fileName,strlen(fileName)+1, fileName);

	this->animationName = new char[strlen(animationName)+1];
	strcpy_s(this->animationName,strlen(animationName)+1, animationName);

	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;

	this->animationLoop = new char[strlen(animationLoop)+1];
	strcpy_s(this->animationLoop,strlen(animationLoop)+1, animationLoop);
}

char* AnimationLine::getFileName()
{
	return fileName;
}

char* AnimationLine::getAnimationName()
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

char* AnimationLine::getAnimationLoop()
{
	return animationLoop;
}

AnimationLine::~AnimationLine(void)
{
       delete[] this->fileName;
       delete[] this->animationName;
       delete[] this->animationLoop;
}