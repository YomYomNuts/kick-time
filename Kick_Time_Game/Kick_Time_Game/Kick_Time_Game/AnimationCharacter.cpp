#include "AnimationCharacter.h"
#include "GameManager.h"


AnimationCharacter::AnimationCharacter(void)
{
	this->animationData = NULL;
	this->posX = 0;
	++animationNumber;
}

AnimationCharacter::AnimationCharacter(int indexAnimation)
{
	this->animationData = &animationDataArray[indexAnimation];
	this->posX = this->animationData->getPosX();
	Animation::setId(++animationNumber);
}

AnimationCharacter::~AnimationCharacter(void)
{
	delete this->animationData;
}

const AnimationData* AnimationCharacter::getAnimationData()
{
	return this->animationData;
}

void AnimationCharacter::updateAnimation()
{
	bool animationDone = Animation::getAnimationDoneState();
	int frameCounter = Animation::getFrameCounter();
	int currentFrame  = Animation::getCurrentFrame();

	if(!animationDone && frameCounter == animationData->getFramerate())
	{
		if(currentFrame == 0)
			this->posX = this->animationData->getPosX();
		else
			this->posX += this->animationData->getSpriteWidth();

		if(currentFrame >= this->animationData->getSpriteNb()-1)
		{
			Animation::setAnimationDoneState(true);
			animationDone = true;
		}

		if(animationDone && this->animationData->getAnimationLoop())
		{
			Animation::setAnimationDoneState(false);
			animationDone = false;
			Animation::setCurrentFrame(0);
			currentFrame = 0;
		}
		else
		{
			Animation::setCurrentFrame(++currentFrame);
		}

		Animation::setFrameCounter(-1);
		frameCounter = -1;
	}

	Animation::setFrameCounter(++frameCounter);
}

void AnimationCharacter::renderAnimation(sf::Sprite * sprite)
{
	int posX;
	int posY;
	int width;
	int height;
	string name;

	posX = this->posX;
	posY = this->animationData->getPosY();
	width = this->animationData->getSpriteWidth();
	height = this->animationData->getSpriteHeight();
	name = this->animationData->getFileName();

	if (width < 0)
	{
		posX += width;
		width = -width;
	}

	sprite->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(name));
	sprite->setTextureRect(sf::IntRect(posX, posY, width, height));

	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*sprite);
}

int AnimationCharacter::getPosX()
{
	return this->posX;
}

void AnimationCharacter::setPosX(int x)
{
	this->posX = x;
}

void AnimationCharacter::resetAnimation()
{
	this->posX = this->animationData->getPosX();
	Animation::setCurrentFrame(0);
	Animation::setFrameCounter(0);
}

void AnimationCharacter::changeAnimation(int indexAnimationData)
{
	this->animationData = &animationDataArray[indexAnimationData];
	this->posX = this->animationData->getPosX();
	Animation::setCurrentFrame(0);
	Animation::setFrameCounter(0);
	Animation::setAnimationDoneState(false);
}
