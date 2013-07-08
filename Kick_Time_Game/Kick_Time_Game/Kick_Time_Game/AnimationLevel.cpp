#include "AnimationLevel.h"
#include "GameManager.h"


AnimationLevel::AnimationLevel(void)
{
	this->animationData = NULL;
	this->posX = 0;
	++AnimationLevel::animationNumber;
	this->spritePosition = new Position(0,0);
	this->originalSpritePosition = new Position(0,0);
}

AnimationLevel::AnimationLevel(int levelNumber, int indexAnimation)
{
	this->animationData = &(levelAnimDataArray.at(levelNumber).at(indexAnimation));
	this->posX = this->animationData->getPosX();
	Animation::setId(++AnimationLevel::animationNumber);
	this->spritePosition = new Position(this->animationData->getAnimPosX(),this->animationData->getAnimPosY());
	this->originalSpritePosition = new Position(this->animationData->getAnimPosX(),this->animationData->getAnimPosY());
}

AnimationLevel::~AnimationLevel(void)
{
	delete this->animationData;
	delete this->spritePosition;
	delete this->originalSpritePosition;
}

const LevelAnimationData* AnimationLevel::getAnimationData()
{
	return this->animationData;
}

void AnimationLevel::updateAnimation()
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

void AnimationLevel::renderAnimation(sf::Sprite * sprite)
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

int AnimationLevel::getPosX()
{
	return this->posX;
}

void AnimationLevel::setPosX(int x)
{
	this->posX = x;
}

void AnimationLevel::resetAnimation()
{
	this->posX = this->animationData->getPosX();
	Animation::setCurrentFrame(0);
	Animation::setFrameCounter(0);
}

double AnimationLevel::getPosXSprite()
{
	return this->spritePosition->getX();
}

double AnimationLevel::getPosYSprite()
{
	return this->spritePosition->getY();
}

void AnimationLevel::setPosXSprite(double x)
{
	this->spritePosition->setX(x);
}

void AnimationLevel::setPosYSprite(double y)
{
	this->spritePosition->setY(y);
}

double AnimationLevel::getPosXOriginalSpritePosition()
{
	return this->originalSpritePosition->getX();
}

double AnimationLevel::getPosYOriginalSpritePosition()
{
	return this->originalSpritePosition->getY();
}
