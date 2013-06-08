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
	int posX;
	int posY;

	if (GameManager::getInstance()->getInputManager()->isPressed(0, POSITION_INPUT_MOVE_RIGHT, -1))
	{

		if(GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->getAnimationData()->getAnimationName() != 2)
			GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->changeAnimation(2);
		
		posX = GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getPosCharacterX();

		GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->setPosCharacterX(posX + MOVE_SPEED);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(0, POSITION_INPUT_MOVE_LEFT, -1))
	{
		if(GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->getAnimationData()->getAnimationName() != 3)
			GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->changeAnimation(3);
	
		posX = GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getPosCharacterX();

		GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->setPosCharacterX(posX - MOVE_SPEED);
	}
	else
	{
		if(GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->getAnimationData()->getAnimationName() != STATE_CHARACTER_STAND_RIGHT)
			GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->changeAnimation(STATE_CHARACTER_STAND_RIGHT);
	}
		//GameManager::getInstance()->getSoundManager()->playSound(SOUND_LEVEL_SCORPION);	
}

void CharacterManager::addCharacter()
{
	this->characterList->push_back(new Character());
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
