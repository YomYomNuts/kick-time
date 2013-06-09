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

		if(GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->getAnimationData()->getAnimationName() != STATE_CHARACTER_FORWARD_RIGHT)
			GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->changeAnimation(STATE_CHARACTER_FORWARD_RIGHT);
		
		GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->moveForward();

	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(0, POSITION_INPUT_MOVE_LEFT, -1))
	{
		if(GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->getAnimationData()->getAnimationName() != STATE_CHARACTER_BACKWARD_RIGHT)
			GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->changeAnimation(STATE_CHARACTER_BACKWARD_RIGHT);
	
		GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->moveBackward();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(0, POSITION_INPUT_MOVE_DOWN, -1))
	{
		if(GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->getAnimationData()->getAnimationName() != STATE_CHARACTER_CROUCH_RIGHT)
			GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getAnimation()->changeAnimation(STATE_CHARACTER_CROUCH_RIGHT);
	
		//GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->moveBackward();
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
