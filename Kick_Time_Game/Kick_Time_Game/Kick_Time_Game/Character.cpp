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
	this->positionCharacter = new Position(SCREEN_SIZE_WIDTH / 2, SCREEN_SIZE_HEIGHT);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID(), this->positionCharacter);
	this->colliderKickPunch = new Collider();
	this->totalHp = 100;
	this->hp = 50;
	this->damage = 2;
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
	this->positionCharacter = new Position(SCREEN_SIZE_WIDTH / 2, SCREEN_SIZE_HEIGHT);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID(), this->positionCharacter);
	this->colliderKickPunch = new Collider();
	this->totalHp = 100;
	this->hp = 50;
	this->damage = 2;
}

Character::~Character(void)
{
	delete this->spriteCharacter;
	delete this->animation;
	delete this->collider;
	delete this->positionCharacter;
	delete this->colliderKickPunch;
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
		this->checkDirection();
		this->updateStand();
		break;
	case CharacterState::STATE_CHARACTER_MOVE_RIGHT:
		this->checkDirection();
		this->updateMoveRight();
		break;
	case CharacterState::STATE_CHARACTER_MOVE_LEFT:
		this->checkDirection();
		this->updateMoveLeft();
		break;
	case CharacterState::STATE_CHARACTER_CROUCH:
		this->checkDirection();
		this->updateCrouch();
		break;
	case CharacterState::STATE_CHARACTER_STANDUP:
		this->checkDirection();
		this->updateStandUp();
		break;
	case CharacterState::STATE_CHARACTER_STEADY_JUMP_UP:
		this->checkDirection();
		this->updateSteadyJumpUp();
		break;
	case CharacterState::STATE_CHARACTER_STEADY_JUMP_DOWN:
		this->checkDirection();
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
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_STEADY_JUMP_UP;
		this->updateAnimationCharacter();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
}

void Character::updateMoveRight()
{
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1) && this->toward == RIGHT)
		{
			this->state = CharacterState::STATE_CHARACTER_FORWARD_JUMP;
			this->updateAnimationCharacter();
		}
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
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1) && this->toward == LEFT)
		{
			this->state = CharacterState::STATE_CHARACTER_FORWARD_JUMP;
			this->updateAnimationCharacter();
		}

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
	this->moveUp();
//	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1))
//	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = CharacterState::STATE_CHARACTER_STEADY_JUMP_DOWN;
			this->updateAnimationCharacter();
		}
/*	}
	else
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}*/
}

void Character::updateSteadyJumpDown()
{
	this->moveDown();

	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateForwardJump()
{
	int currentFrame = this->animation->getCurrentFrame();
	int maxFrame = this->animation->getAnimationData()->getSpriteNb();
	
	//if(maxFrame%2 == 0)
	//	++maxFrame;

	if(this->toward == RIGHT)
		this->moveRight();
	else
		this->moveLeft();

	if(currentFrame < maxFrame/2)
		this->moveUp();
	else
		this->moveDown();

	if (this->animation->getAnimationDoneState())
	{
		this->setPosCharacterY(SCREEN_SIZE_HEIGHT);
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
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
	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}

	// Update position kick
	if (this->colliderKickPunch->getPosition() != NULL)
	{
		Character * enemy = GameManager::getInstance()->getCharacterManager()->getClosestCharacter(this->indexCharacter, this->colliderKickPunch->getPosition());
		if (enemy != NULL && this->colliderKickPunch->AreColliding(enemy->getCollider()))
		{
			enemy->hitCharacter(this->damage);
			this->colliderKickPunch->setPosition(NULL);
		}
		else if (this->colliderKickPunch->getPosition()->getX() != this->positionCharacter->getX() + this->colliderKickPunch->getColliderData()->getPosX())
		{
			double distance = this->colliderKickPunch->getColliderData()->getPosX() - this->collider->getColliderData()->getPosX();
			double speed = this->animation->getAnimationData()->getFramerate() * this->animation->getAnimationData()->getSpriteNb();
			this->colliderKickPunch->getPosition()->setX(this->colliderKickPunch->getPosition()->getX() + distance / speed);
		}
	}
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
	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
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
	this->spriteCharacter->setPosition((float)this->positionCharacter->getX(), (float)this->positionCharacter->getY() - height);
	this->animation->renderAnimation(this->spriteCharacter);

#ifdef DEBUG_SHOW_COLLIDER
	// Debug collider
	this->collider->renderCollider(sf::Color::Red);
	if (this->colliderKickPunch->getPosition() != NULL)
		this->colliderKickPunch->renderCollider(sf::Color::Green);
#endif
}

void Character::setPosCharacterX(double posX)
{
	this->positionCharacter->setX(posX);
}

void Character::setPosCharacterY(double posY)
{
	this->positionCharacter->setY(posY);
}

double Character::getPosCharacterX()
{
	return this->positionCharacter->getX();
}

double Character::getPosCharacterY()
{
	return this->positionCharacter->getY();
}

int Character::getTotalHp()
{
	return this->totalHp;
}

int Character::getHp()
{
	return this->hp;
}

int Character::getIndexCharacter()
{
	return this->indexCharacter;
}

Collider* Character::getCollider()
{
	return this->collider;
}

void Character::moveRight()
{
	this->setPosCharacterX(this->getPosCharacterX() + MOVE_SPEED);
}

void Character::moveLeft()
{
	this->setPosCharacterX(this->getPosCharacterX() - MOVE_SPEED);
}

void Character::moveUp()
{
	this->setPosCharacterY(this->getPosCharacterY() - 2*MOVE_SPEED);
}

void Character::moveDown()
{
	this->setPosCharacterY(this->getPosCharacterY() + 2*MOVE_SPEED);
}

void Character::updateAnimationCharacter()
{
	this->animation->changeAnimation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);;
	this->collider->changeColliderData(this->animation->getAnimationData()->getColliderID());
	this->colliderKickPunch->changeColliderData(this->animation->getAnimationData()->getColliderKickPunchID());
}

void Character::checkDirection()
{
	CharacterDirection currentDirection = this->toward;

	if(this->indexCharacter % 2 == 0)
	{
		if(this->positionCharacter->getX() - GameManager::getInstance()->getCharacterManager()->getCharacters()->at(1)->getPosCharacterX() < 0)
		{
			if(currentDirection != RIGHT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = RIGHT;
					this->updateAnimationCharacter();
				}
				else
				{
					/*if (this->animation->getAnimationDoneState())
					{
						this->toward = RIGHT;
						this->updateAnimationCharacter();
					}*/
				}
			}
		}
		else
		{
			if(currentDirection != LEFT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = LEFT;
					this->updateAnimationCharacter();
				}
				else
				{
					/*if (this->animation->getAnimationDoneState())
					{
						this->toward = LEFT;
						this->updateAnimationCharacter();
					}*/
				}
			}
		}
	}
	else
	{
		if(this->positionCharacter->getX() - GameManager::getInstance()->getCharacterManager()->getCharacters()->at(0)->getPosCharacterX() < 0)
		{
			if(currentDirection != RIGHT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = RIGHT;
					this->updateAnimationCharacter();
				}
				else
				{
					if (this->animation->getAnimationDoneState())
					{
						this->toward = RIGHT;
						this->updateAnimationCharacter();
					}
				}
			}
		}
		else
		{
			if(currentDirection != LEFT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = LEFT;
					this->updateAnimationCharacter();
				}
				else
				{
					if (this->animation->getAnimationDoneState())
					{
						this->toward = LEFT;
						this->updateAnimationCharacter();
					}
				}
			}
		}
	}
}

void Character::hitCharacter(int damage)
{
	if (this->state != STATE_CHARACTER_GUARD  && this->state != STATE_CHARACTER_LOW_GUARD)
	{
		this->hp -= damage;
		if (this->hp < 0)
			this->hp = 0;

		if (this->state == STATE_CHARACTER_CROUCH || this->state == STATE_CHARACTER_STANDUP || this->state == STATE_CHARACTER_CROUCHED_KICK ||
			this->state == STATE_CHARACTER_CROUCHED_PUNCH || this->state == STATE_CHARACTER_LOW_HIT || this->state == STATE_CHARACTER_CROUCHED)
			this->state = STATE_CHARACTER_LOW_HIT;
		else
			this->state = STATE_CHARACTER_HIT;
		this->updateAnimationCharacter();
	}
}