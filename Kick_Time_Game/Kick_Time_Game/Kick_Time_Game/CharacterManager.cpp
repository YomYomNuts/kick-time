#include "CharacterManager.h"
#include "GameManager.h"
#include "SoundData.h"
#include "InputManager_Defines.h"

CharacterManager::CharacterManager(void)
{
	this->characterList = new vector<Character>();
}


CharacterManager::~CharacterManager(void)
{
	delete[] characterList;
}

void CharacterManager::initializeCharacterManager()
{
}

void CharacterManager::updateCharacterManager()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(0, POSITION_INPUT_MOVE_UP, -1))
		GameManager::getInstance()->getSoundManager()->playSound(SOUND_LEVEL_SCORPION);


}

void CharacterManager::addCharacter()
{
	this->characterList->push_back(*new Character());
}

void CharacterManager::renderCharacterManager()
{
	int i;

	for(i = 0; i < this->characterList->size(); ++i)
	{
		this->characterList->at(i).renderCharacter();
	}
}