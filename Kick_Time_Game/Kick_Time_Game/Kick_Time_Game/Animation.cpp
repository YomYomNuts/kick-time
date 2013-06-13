#include "Animation.h"
#include "GameManager.h"

#include <iostream>


Animation::Animation(void)
{
	this->animationData = NULL;
	this->posX = 0;
	this->currentFrame = 0;
	this->frameCounter = 0;
	this->animationDone = false;
	this->id = this->animationNumber++;
}

Animation::Animation(int indexAnimationData)
{
	this->animationData = &animationDataArray[indexAnimationData];
	this->posX = this->animationData->getPosX();
	this->currentFrame = 0;
	this->frameCounter = 0;
	this->animationDone = false;
	this->id = this->animationNumber++;
}

Animation::~Animation(void)
{
	delete this->animationData;
}

void Animation::updateAnimation()
{
	if(!this->animationDone && frameCounter == animationData->getFramerate())
	{
		if(this->currentFrame == 0)
			this->posX = this->animationData->getPosX();
		else
			this->posX += this->animationData->getSpriteWidth();

		if(this->currentFrame >= this->animationData->getSpriteNb()-1)
			this->animationDone = true;

		if(this->animationDone && this->animationData->getAnimationLoop())
		{
			this->animationDone = false;
			this->currentFrame = 0;
		}
		else
		{
			++this->currentFrame;
		}

		this->frameCounter = -1;
	}
	
	++this->frameCounter;
}

void Animation::renderAnimation(sf::Sprite * sprite)
{
	int posX = this->posX;
	int posY = this->animationData->getPosY();
	int width = this->animationData->getSpriteWidth();
	int height = this->animationData->getSpriteHeight();
	
	if (width < 0)
	{
		posX += width;
		width = -width;
	}

	sprite->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->animationData->getFileName()));
	sprite->setTextureRect(sf::IntRect(posX, posY, width, height));

	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*sprite);
}

int Animation::getPosX()
{
	return this->posX;
}

int Animation::getCurrentFrame()
{
	return this->currentFrame;
}

int Animation::getId()
{
	return this->id;
}

void Animation::setPosX(int x)
{
	this->posX = x;
}

void Animation::setCurrentFrame(int frame)
{
	this->currentFrame = frame;
}

void Animation::resetAnimation()
{
	this->posX = this->animationData->getPosX();
	this->currentFrame = 0;
	this->frameCounter = 0;
}

void Animation::changeAnimation(int indexAnimationData)
{
	this->animationData = &animationDataArray[indexAnimationData];
	this->posX = this->animationData->getPosX();
	this->currentFrame = 0;
	this->frameCounter = 0;
	this->animationDone = false;
}

const AnimationData* Animation::getAnimationData()
{
	return this->animationData;
}

bool Animation::getAnimationDoneState()
{
	return this->animationDone;
}