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
	this->shiftPositionXCharacter = 0;
	this->colliderName = "COLLIDER_NULL";
	this->colliderKickPunchName = "COLLIDER_NULL";
}

AnimationLine::AnimationLine(string fileName, string animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int shiftPositionXCharacter, string colliderName, string colliderKickPunchName)
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
	this->shiftPositionXCharacter = shiftPositionXCharacter;
	this->colliderName = colliderName;
	this->colliderKickPunchName = colliderKickPunchName;
}

AnimationLine::~AnimationLine(void)
{
}

string AnimationLine::getFileName()
{
	return this->fileName;
}

string AnimationLine::getAnimationName()
{
	return this->animationName;
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

int AnimationLine::getShiftPositionXCharacter()
{
	return this->shiftPositionXCharacter;
}

string AnimationLine::getColliderName()
{
	return this->colliderName;
}

string AnimationLine::getColliderKickPunchName()
{
	return this->colliderKickPunchName;
}