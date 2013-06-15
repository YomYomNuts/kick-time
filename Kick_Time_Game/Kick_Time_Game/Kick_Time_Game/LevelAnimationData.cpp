#include "LevelAnimationData.h"


LevelAnimationData::LevelAnimationData(void)
{
	this->animPosition = new Position(0,0);
}

LevelAnimationData::~LevelAnimationData(void)
{
}

LevelAnimationData::LevelAnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, double posAnimX, double posAnimY):AnimationData(fileName, animationName,  posX,  posY, spriteWidth,  spriteHeight,  framerate, spriteNb, animationLoop)
{
	this->animPosition = new Position(posAnimX,posAnimY);
}

double LevelAnimationData::getAnimPosX() const
{
	return this->animPosition->getX();
}

double LevelAnimationData::getAnimPosY() const
{
	return this->animPosition->getY();
}