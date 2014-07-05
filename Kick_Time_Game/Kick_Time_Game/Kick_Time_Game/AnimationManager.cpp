#include "AnimationManager.h"


AnimationManager::AnimationManager(void)
{
	this->animationCharacterList = new vector<AnimationCharacter*>();
	this->animationLevelList = new vector<AnimationLevel*>();
}

AnimationManager::~AnimationManager(void)
{
    for (unsigned int i = 0; i < this->animationCharacterList->size(); ++i)
    {
        delete this->animationCharacterList->at(i);
    }
	delete this->animationCharacterList;
    for (unsigned int i = 0; i < this->animationLevelList->size(); ++i)
    {
        delete this->animationLevelList->at(i);
    }
	delete this->animationLevelList;
}

void AnimationManager::initializeAnimationManager()
{
}

void AnimationManager::updateAnimationManager()
{
	for(unsigned int i = 0; i < this->animationCharacterList->size(); ++i)
	{
		this->animationCharacterList->at(i)->updateAnimation();
	}

	for(unsigned int i = 0; i < this->animationLevelList->size(); ++i)
	{
		this->animationLevelList->at(i)->updateAnimation();
	}
}

void AnimationManager::addCharacterAnimation(AnimationCharacter* anim)
{
	this->animationCharacterList->push_back(anim);
}

void AnimationManager::removeCharacterAnimation(AnimationCharacter* anim)
{
	unsigned int j = 0;

	for(unsigned int i = 0; i < this->animationCharacterList->size(); ++i)
	{
		if(this->animationCharacterList->at(i)->getId() == anim->getId())
			j = i;
	}

    delete this->animationCharacterList->at(j);
	this->animationCharacterList->erase(this->animationCharacterList->begin()+j);
}

void AnimationManager::addLevelAnimation(AnimationLevel* anim)
{
	this->animationLevelList->push_back(anim);
}

void AnimationManager::removeLevelAnimation(AnimationLevel* anim)
{
	unsigned int j = 0;

	for(unsigned int i = 0; i < this->animationLevelList->size(); ++i)
	{
		if(this->animationLevelList->at(i)->getId() == anim->getId())
			j = i;
	}

    delete this->animationLevelList->at(j);
	this->animationLevelList->erase(this->animationLevelList->begin()+j);
}

void AnimationManager::cleanAnimations()
{
	for(unsigned int i = 0; i < this->animationCharacterList->size(); ++i)
	{
	    delete this->animationCharacterList->at(i);
	}
	this->animationCharacterList->clear();
	for(unsigned int i = 0; i < this->animationLevelList->size(); ++i)
	{
        delete this->animationLevelList->at(i);
	}
	this->animationLevelList->clear();
}
