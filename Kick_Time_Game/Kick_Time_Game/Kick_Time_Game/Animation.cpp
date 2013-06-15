#include "Animation.h"
#include "GameManager.h"

#include <iostream>


Animation::Animation(void)
{
	this->currentFrame = 0;
	this->frameCounter = 0;
	this->animationDone = false;
	this->id = 0;
}

Animation::~Animation(void)
{
}


int Animation::getCurrentFrame()
{
	return this->currentFrame;
}

int Animation::getId()
{
	return this->id;
}

void Animation::setCurrentFrame(int frame)
{
	this->currentFrame = frame;
}

bool Animation::getAnimationDoneState()
{
	return this->animationDone;
}

const LevelAnimationData * Animation::getLevelAnimationData()
{
	return this->levelAnimData;
}

void Animation::setId(int id)
{
	this->id = id;
}
void Animation::setFrameCounter(int frame)
{
	this->frameCounter = frame;
}

int Animation::getFrameCounter()
{
	return this->frameCounter;
}

void Animation::setAnimationDoneState(bool state)
{
	this->animationDone = state;
}