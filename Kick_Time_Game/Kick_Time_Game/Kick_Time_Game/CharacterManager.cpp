#include "CharacterManager.h"
#include "GameManager.h"
#include "SoundData.h"
#include "InputManager_Defines.h"

CharacterManager::CharacterManager(void)
{
}


CharacterManager::~CharacterManager(void)
{
}

void CharacterManager::initializeCharacterManager()
{
}

void CharacterManager::updateCharacterManager()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(0, POSITION_INPUT_MOVE_UP, -1))
		GameManager::getInstance()->getSoundManager()->playSound(SOUND_LEVEL_SCORPION);
}