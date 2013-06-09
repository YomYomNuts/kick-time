#include "AnimationManager.h"


AnimationManager::AnimationManager(void)
{
	this->animationList = new vector<Animation*>();
}

AnimationManager::~AnimationManager(void)
{
	delete this->animationList;
}

void AnimationManager::initializeAnimationManager()
{
}

void AnimationManager::updateAnimationManager()
{
	for(unsigned int i = 0; i < this->animationList->size(); ++i)
	{
		this->animationList->at(i)->updateAnimation();
	}
}

void AnimationManager::addAnimation(Animation* anim)
{
	this->animationList->push_back(anim);
}

void AnimationManager::removeAnimation(Animation* anim)
{
	unsigned int j = 0;

	for(unsigned int i = 0; i < this->animationList->size(); ++i)
	{
		if(this->animationList->at(i)->getId() == anim->getId())
			j = i;
	}

	this->animationList->erase(this->animationList->begin()+j);
}
