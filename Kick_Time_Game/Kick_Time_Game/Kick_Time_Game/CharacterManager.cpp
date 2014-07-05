#include "CharacterManager.h"
#include "GameManager.h"
#include "SoundData.h"
#include "InputManager_Defines.h"
#include "Character_Defines.h"
#include "CharacterData.h"

#include <climits>
#include <cmath>

CharacterManager::CharacterManager(void)
{
	this->characterList = new vector<Character*>();
	this->characterDataIndex = new vector<int>();
}

CharacterManager::~CharacterManager(void)
{
    if (this->characterList != NULL)
    {
        for (unsigned int i = 0; i < this->characterList->size(); ++i)
        {
            delete this->characterList->at(i);
        }
        delete this->characterList;
    }
	delete this->characterDataIndex;
}

void CharacterManager::initializeCharacterManager()
{
}

void CharacterManager::updateCharacterManager()
{
	for(unsigned int i = 0; i < this->characterList->size(); ++i)
	{
		this->characterList->at(i)->updateCharacter();
	}
}

void CharacterManager::addCharacterDataIndexAt(int indexCharacter, int indexTypeCharacter)
{
	if ((int)this->characterDataIndex->size() > indexCharacter)
    {
        int previous = this->characterDataIndex->at(indexCharacter);
		this->characterDataIndex->at(indexCharacter) = indexTypeCharacter;
		this->characterDataIndex->push_back(previous);
    }
	else
		this->characterDataIndex->push_back(indexTypeCharacter);
}

void CharacterManager::removeCharacterDataIndex(int indexCharacter)
{
	this->characterDataIndex->erase(this->characterDataIndex->begin() + indexCharacter);
}

vector<int>* CharacterManager::getCharactersDataIndex()
{
	return this->characterDataIndex;
}

void CharacterManager::loadCharacters()
{
    this->unloadCharacters();
    for (unsigned int i = 0; i < this->characterDataIndex->size(); ++i)
    {
        this->addCharacter(this->characterDataIndex->at(i));
    }
}

void CharacterManager::unloadCharacters()
{
    for (unsigned int i = 0; i < this->characterList->size(); ++i)
    {
        delete this->characterList->at(i);
    }
    this->characterList->clear();
}

void CharacterManager::addCharacter(int indexTypeCharacter)
{
	this->characterList->push_back(new Character(this->characterList->size(), indexTypeCharacter));
}

void CharacterManager::removeCharacter(int indexCharacter)
{
    delete this->characterList->at(indexCharacter);
	this->characterList->erase(this->characterList->begin() + indexCharacter);
}

vector<Character*>* CharacterManager::getCharacters()
{
	return this->characterList;
}

void CharacterManager::renderCharacterManager()
{
	for(unsigned int i = 0; i < this->characterList->size(); ++i)
	{
		this->characterList->at(i)->renderCharacter();
	}
}

Character* CharacterManager::getClosestCharacter(int withoutThisIndex, Position * position)
{
	double distance = (double)INT_MAX, tempDistance = 0;
	Character * closest = NULL;
	for(unsigned int i = 0; i < this->characterList->size(); ++i)
	{
		tempDistance = fabs(position->getX() - this->characterList->at(i)->getPosCharacterX()) + fabs(position->getY() - this->characterList->at(i)->getPosCharacterY());
		if (this->characterList->at(i)->getIndexCharacter() != withoutThisIndex && tempDistance < distance)
		{
			distance = tempDistance;
			closest = this->characterList->at(i);
		}
	}
	return closest;
}

Character* CharacterManager::getFarestCharacter(int withoutThisIndex, Position * position)
{
	double distance = (double)INT_MIN, tempDistance = 0;
	Character * farest = NULL;
	for(unsigned int i = 0; i < this->characterList->size(); ++i)
	{
		tempDistance = abs(position->getX() - this->characterList->at(i)->getPosCharacterX());
		if (this->characterList->at(i)->getIndexCharacter() != withoutThisIndex && tempDistance > distance)
		{
			distance = tempDistance;
			farest = this->characterList->at(i);
		}
	}
	return farest;
}

Character* CharacterManager::getCharacterWithMaxHp()
{
	int hp = -1;
	Character * characterMaxHp = NULL;
	for(unsigned int i = 0; i < this->characterList->size(); ++i)
	{
		if (this->characterList->at(i)->getHp() > hp)
		{
			hp = this->characterList->at(i)->getHp();
			characterMaxHp = this->characterList->at(i);
		}
	}
	return characterMaxHp;
}
