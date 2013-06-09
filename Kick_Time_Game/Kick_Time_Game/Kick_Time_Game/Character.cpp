#include "Character.h"
#include "Character_Defines.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"
#include "Debug.h"

#include <iostream>

Character::Character(void)
{
	this->indexCharacter = 0;
	if(this->indexCharacter % 2 == 0)
		this->toward = CharacterDirection::RIGHT;
	else
		this->toward = CharacterDirection::LEFT;
	
	this->spriteCharacter = new sf::Sprite();
	this->state = CharacterState::STATE_CHARACTER_STAND;
	this->animation = new Animation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID());
	this->posCharacterX = SCREEN_SIZE_WIDTH / 2;
	this->posCharacterY = SCREEN_SIZE_HEIGHT;
	this->totalHp = 100;
	this->hp = 50;
}

Character::Character(int indexCharacter)
{
	this->indexCharacter = indexCharacter;
	if(this->indexCharacter % 2 == 0)
		this->toward = CharacterDirection::RIGHT;
	else
		this->toward = CharacterDirection::LEFT;
	
	this->spriteCharacter = new sf::Sprite();
	this->state = CharacterState::STATE_CHARACTER_STAND;
	this->animation = new Animation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID());
	this->posCharacterX = SCREEN_SIZE_WIDTH / 2;
	this->posCharacterY = SCREEN_SIZE_HEIGHT;
	this->totalHp = 100;
	this->hp = 50;
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
	case CharacterState::STATE_CHARACTER_STAND:
		this->updateStand();
		break;
	case CharacterState::STATE_CHARACTER_MOVE_RIGHT:
		this->updateMoveRight();
		break;
	case CharacterState::STATE_CHARACTER_MOVE_LEFT:
		this->updateMoveLeft();
		break;
	case CharacterState::STATE_CHARACTER_CROUCH:
		this->updateCrouch();
		break;
	case CharacterState::STATE_CHARACTER_STANDUP:
		this->updateStandUp();
		break;
	case CharacterState::STATE_CHARACTER_STEADY_JUMP_UP:
		this->updateSteadyJumpUp();
		break;
	case CharacterState::STATE_CHARACTER_STEADY_JUMP_DOWN:
		this->updateSteadyJumpDown();
		break;
	case CharacterState::STATE_CHARACTER_FORWARD_JUMP:
		this->updateForwardJump();
		break;
	case CharacterState::STATE_CHARACTER_GUARD:
		this->updateGuard();
		break;
	case CharacterState::STATE_CHARACTER_LOW_GUARD:
		this->updateLowGuard();
		break;
	case CharacterState::STATE_CHARACTER_PUNCH:
		this->updatePunch();
		break;
	case CharacterState::STATE_CHARACTER_KICK:
		this->updateKick();
		break;
	case CharacterState::STATE_CHARACTER_CROUCHED_KICK:
		this->updateCrouchedKick();
		break;
	case CharacterState::STATE_CHARACTER_CROUCHED_PUNCH:
		this->updateCrouchedPunch();
		break;
	case CharacterState::STATE_CHARACTER_JUMPED_PUNCH:
		this->updateJumpedPunch();
		break;
	case CharacterState::STATE_CHARACTER_JUMPED_KICK:
		this->updateJumpedKick();
		break;
	case CharacterState::STATE_CHARACTER_HIT:
		this->updateHit();
		break;
	case CharacterState::STATE_CHARACTER_LOW_HIT:
		this->updateLowHit();
		break;
	case CharacterState::STATE_CHARACTER_VICTORY:
		this->updateVictory();
		break;
	case CharacterState::STATE_CHARACTER_CROUCHED:
		this->updateCrouched();
		break;
	}
}

void Character::updateStand()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
		this->updateAnimationCharacter();
		this->moveRight();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
		this->updateAnimationCharacter();
		this->moveLeft();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCH;
		this->updateAnimationCharacter();
	}
}

void Character::updateMoveRight()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{
		this->moveRight();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
		this->updateAnimationCharacter();
		this->moveLeft();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCH;
		this->updateAnimationCharacter();
	}
	else
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateMoveLeft()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
		this->updateAnimationCharacter();
		this->moveRight();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
	{
		this->moveLeft();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCH;
		this->updateAnimationCharacter();
	}
	else
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateCrouch()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCHED;
			this->updateAnimationCharacter();
		}
	}
	else
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateStandUp()
{
	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateSteadyJumpUp()
{
}

void Character::updateSteadyJumpDown()
{
}

void Character::updateForwardJump()
{
}

void Character::updateGuard()
{
}

void Character::updateLowGuard()
{
}

void Character::updatePunch()
{
}

void Character::updateKick()
{
}

void Character::updateCrouchedKick()
{
}

void Character::updateCrouchedPunch()
{
}

void Character::updateJumpedPunch()
{
}

void Character::updateJumpedKick()
{
}

void Character::updateHit()
{
}

void Character::updateLowHit()
{
}

void Character::updateVictory()
{
}

void Character::updateCrouched()
{
	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_STANDUP;
		this->updateAnimationCharacter();
	}
}

void Character::renderCharacter()
{
	int height = this->animation->getAnimationData()->getSpriteHeight();
	this->spriteCharacter->setPosition((float)this->posCharacterX, (float)this->posCharacterY - height);
	this->animation->renderAnimation(this->spriteCharacter);

#ifdef DEBUG_SHOW_COLLIDER
	// Debug collider
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(1);
	rectangle.setSize(sf::Vector2f((float)this->collider->getColliderData()->getHalfSizeX()*2, (float)this->collider->getColliderData()->getHalfSizeY()*2));
	rectangle.setPosition((float)this->posCharacterX + this->collider->getColliderData()->getPosX() - this->collider->getColliderData()->getHalfSizeX(), (float)this->posCharacterY - this->collider->getColliderData()->getPosY() - this->collider->getColliderData()->getHalfSizeY());
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(rectangle);
#endif
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

void Character::moveRight()
{
	this->setPosCharacterX(this->getPosCharacterX() + MOVE_SPEED);
}

void Character::moveLeft()
{
	this->setPosCharacterX(this->getPosCharacterX() - MOVE_SPEED);
}

void Character::updateAnimationCharacter()
{
	this->animation->changeAnimation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);;
	this->collider->setColliderData(this->animation->getAnimationData()->getColliderID());
}