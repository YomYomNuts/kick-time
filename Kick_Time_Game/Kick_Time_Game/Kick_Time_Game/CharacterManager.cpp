#include "CharacterManager.h"
#include "GameManager.h"
#include "SoundData.h"
#include "InputManager_Defines.h"
#include "Character_Defines.h"


CharacterManager::CharacterManager(void)
{
	this->characterList = new vector<Character*>();
}

CharacterManager::~CharacterManager(void)
{
	delete characterList;
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

void CharacterManager::addCharacter()
{
	this->characterList->push_back(new Character(this->characterList->size()));
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
