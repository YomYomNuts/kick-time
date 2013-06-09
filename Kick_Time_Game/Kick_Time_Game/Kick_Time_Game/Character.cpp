#include "Character.h"
#include "Character_Defines.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"

#include <iostream>

Character::Character(void)
{
	this->state = STATE_CHARACTER_STAND_RIGHT;
	this->animation = new Animation(this->state);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->spriteCharacter = new sf::Sprite();
	this->posCharacterX = SCREEN_SIZE_WIDTH / 2;
	this->posCharacterY = SCREEN_SIZE_HEIGHT;
	this->totalHp = 100;
	this->hp = 50;

	if(GameManager::getInstance()->getCharacterManager()->getCharacters()->size() == 0)
		this->toward = RIGHT;
	else
		this->toward = LEFT;
}

Character::~Character(void)
{
	delete this->animation;
}

Animation* Character::getAnimation()
{
	return animation;
}

void Character::updateCharacter()
{
	switch (this->state)
	{
	case STATE_CHARACTER_STAND_RIGHT:
		break;
	case STATE_CHARACTER_STAND_LEFT:
		break;
	case STATE_CHARACTER_FORWARD_RIGHT:
		break;
	case STATE_CHARACTER_FORWARD_LEFT:
		break;
	case STATE_CHARACTER_BACKWARD_RIGHT:
		break;
	case STATE_CHARACTER_BACKWARD_LEFT:
		break;
	case STATE_CHARACTER_CROUCH_RIGHT:
		break;
	case STATE_CHARACTER_CROUCH_LEFT:
		break;
	case STATE_CHARACTER_STANDUP_RIGHT:
		break;
	case STATE_CHARACTER_STANDUP_LEFT:
		break;
	case STATE_CHARACTER_STEADY_JUMP_UP_RIGHT:
		break;
	case STATE_CHARACTER_STEADY_JUMP_UP_LEFT:
		break;
	case STATE_CHARACTER_STEADY_JUMP_DOWN_RIGHT:
		break;
	case STATE_CHARACTER_STEADY_JUMP_DOWN_LEFT:
		break;
	case STATE_CHARACTER_FORWARD_JUMP_RIGHT:
		break;
	case STATE_CHARACTER_FORWARD_JUMP_LEFT:
		break;
	case STATE_CHARACTER_GUARD_RIGHT:
		break;
	case STATE_CHARACTER_GUARD_LEFT:
		break;
	case STATE_CHARACTER_LOW_GUARD_RIGHT:
		break;
	case STATE_CHARACTER_LOW_GUARD_LEFT:
		break;
	case STATE_CHARACTER_PUNCH_RIGHT:
		break;
	case STATE_CHARACTER_PUNCH_LEFT:
		break;
	case STATE_CHARACTER_KICK_RIGHT:
		break;
	case STATE_CHARACTER_KICK_LEFT:
		break;
	case STATE_CHARACTER_CROUCHED_KICK_RIGHT:
		break;
	case STATE_CHARACTER_CROUCHED_KICK_LEFT:
		break;
	case STATE_CHARACTER_CROUCHED_PUNCH_RIGHT:
		break;
	case STATE_CHARACTER_CROUCHED_PUNCH_LEFT:
		break;
	case STATE_CHARACTER_JUMPED_KICK_RIGHT:
		break;
	case STATE_CHARACTER_JUMPED_KICK_LEFT:
		break;
	case STATE_CHARACTER_HIT_RIGHT:
		break;
	case STATE_CHARACTER_HIT_LEFT:
		break;
	case STATE_CHARACTER_LOW_HIT_RIGHT:
		break;
	case STATE_CHARACTER_LOW_HIT_LEFT:
		break;
	case STATE_CHARACTER_VICTORY:
		break;
	}
}

void Character::updateStand()
{
}

void Character::updateJump()
{
}

void Character::renderCharacter()
{
	int posX = this->animation->getPosX();
	int posY = this->animation->getPosY();
	int width = this->animation->getAnimationDataWidth();
	int height = this->animation->getAnimationDataHeight();

	this->spriteCharacter->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->animation->getAnimationDataName()));
	this->spriteCharacter->setTextureRect(sf::IntRect(posX, posY, width, height));
	this->spriteCharacter->setPosition(this->posCharacterX, this->posCharacterY - height);

	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteCharacter);
}


void Character::setPosCharacterX(int posX)
{
	this->posCharacterX = posX;
}

void Character::setPosCharacterY(int posY)
{
	this->posCharacterY = posY;
}

int Character::getPosCharacterX()
{
	return this->posCharacterX;
}

int Character::getPosCharacterY()
{
	return this->posCharacterY;
}

int Character::getTotalHp()
{
	return this->totalHp;
}

int Character::getHp()
{
	return this->hp;
}

void Character::moveForward()
{
	if(toward == RIGHT)
		setPosCharacterX(getPosCharacterX() + MOVE_SPEED);
	else
		setPosCharacterX(getPosCharacterX() - MOVE_SPEED);
}

void Character::moveBackward()
{
	if(toward == RIGHT)
		setPosCharacterX(getPosCharacterX() - MOVE_SPEED);
	else
		setPosCharacterX(getPosCharacterX() + MOVE_SPEED);
}