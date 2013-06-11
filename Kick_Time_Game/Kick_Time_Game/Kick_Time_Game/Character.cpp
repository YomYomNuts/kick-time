#include "Character.h"
#include "Character_Defines.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"
#include "Debug.h"

#include <iostream>

Character::Character(void)
{
	double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
	this->indexCharacter = 0;
	if(this->indexCharacter % 2 == 0)
		this->toward = CharacterDirection::RIGHT;
	else
		this->toward = CharacterDirection::LEFT;
	
	this->spriteCharacter = new sf::Sprite();
	this->state = CharacterState::STATE_CHARACTER_STAND;
	this->animation = new Animation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->positionCharacter = new Position(SCREEN_SIZE_WIDTH / 2 - this->animation->getAnimationData()->getShiftPositionXCharacter(), posYFromLevel);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID(), this->positionCharacter);
	this->colliderKickPunch = new Collider();
	this->totalHp = 100;
	this->hp = 50;
	this->damage = 2;
	this->endOfTheScreenReached = false;
}

Character::Character(int indexCharacter)
{
	double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
	double posX = SCREEN_SIZE_WIDTH / 2;

	this->indexCharacter = indexCharacter;
	if(this->indexCharacter % 2 == 0)
	{
		this->toward = CharacterDirection::RIGHT;
		posX -= SHIFT_BETWEEN_CHARACTERS;
	}
	else
	{
		this->toward = CharacterDirection::LEFT;
		posX += SHIFT_BETWEEN_CHARACTERS;
	}
	
	this->spriteCharacter = new sf::Sprite();
	this->state = CharacterState::STATE_CHARACTER_STAND;
	this->animation = new Animation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->positionCharacter = new Position(posX - this->animation->getAnimationData()->getShiftPositionXCharacter(), posYFromLevel);
	cout << this->animation->getAnimationData()->getShiftPositionXCharacter() << endl;
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID(), this->positionCharacter);
	this->colliderKickPunch = new Collider();
	this->totalHp = 100;
	this->hp = 50;
	this->damage = 2;
	this->endOfTheScreenReached = false;
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
	case CharacterState::STATE_CHARACTER_BACKWARD_JUMP:
		this->updateBackwardJump();
		break;
	case CharacterState::STATE_CHARACTER_GUARD:
		this->updateGuard();
		break;
	case CharacterState::STATE_CHARACTER_GUARD_ON:
		this->updateGuardOn();
		break;
	case CharacterState::STATE_CHARACTER_LOW_GUARD:
		this->updateLowGuard();
		break;
	case CharacterState::STATE_CHARACTER_LOW_GUARD_ON:
		this->updateLowGuardOn();
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
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
		this->updateAnimationCharacter();
		this->moveRight(1);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
		this->updateAnimationCharacter();
		this->moveLeft(1);
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
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_GUARD;
		this->updateAnimationCharacter();
	}
}

void Character::updateMoveRight()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1) && this->toward == RIGHT)
		{
			this->state = CharacterState::STATE_CHARACTER_FORWARD_JUMP;
			this->updateAnimationCharacter();
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1) && this->toward == LEFT)
		{
			this->state = CharacterState::STATE_CHARACTER_BACKWARD_JUMP;
			this->updateAnimationCharacter();
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD;
			this->updateAnimationCharacter();
		}

		int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());
		
		if(this->getPosCharacterX() + spriteWidth >= SCREEN_SIZE_WIDTH)
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD;
			this->setPosCharacterX(SCREEN_SIZE_WIDTH - spriteWidth);
			this->endOfTheScreenReached = true;
			this->updateAnimationCharacter();
		}
		else
		{
			this->endOfTheScreenReached = false;
			this->moveRight(1.5);
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
		this->updateAnimationCharacter();
		this->moveLeft(1);
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
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
		this->updateAnimationCharacter();
		this->moveRight(1);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1) && this->toward == LEFT)
		{
			this->state = CharacterState::STATE_CHARACTER_FORWARD_JUMP;
			this->updateAnimationCharacter();
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP, -1) && this->toward == RIGHT)
		{
			this->state = CharacterState::STATE_CHARACTER_BACKWARD_JUMP;
			this->updateAnimationCharacter();
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD;
			this->updateAnimationCharacter();
		}

		int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());
		
		if(this->getPosCharacterX() <= 0)
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD;
			this->setPosCharacterX(0);
			this->endOfTheScreenReached = true;
			this->updateAnimationCharacter();
		}
		else
		{
			this->endOfTheScreenReached = false;
			this->moveLeft(1.5);
		}
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
	this->checkDirection();

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
	this->checkDirection();

	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateSteadyJumpUp()
{
	this->checkDirection();

	this->moveUp(2);
	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STEADY_JUMP_DOWN;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
}

void Character::updateSteadyJumpDown()
{
	this->checkDirection();

	this->moveDown(2);

	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
}

void Character::updateForwardJump()
{
	int currentFrame = this->animation->getCurrentFrame();
	int maxFrame = this->animation->getAnimationData()->getSpriteNb();
	int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());
	
	if(this->toward == RIGHT)
	{
		this->moveRight(2);
		this->endOfTheScreenReached = false;
		if(this->getPosCharacterX() + spriteWidth >= SCREEN_SIZE_WIDTH)
		{
			this->setPosCharacterX(SCREEN_SIZE_WIDTH - spriteWidth);
			this->endOfTheScreenReached = true;
		}
	}
	else
	{
		this->moveLeft(2);
		this->endOfTheScreenReached = false;
		if(this->getPosCharacterX() <= 0)
		{
			this->setPosCharacterX(0);
			this->endOfTheScreenReached = true;
		}
	}
	if(currentFrame < maxFrame/2)
		this->moveUp(2.5);
	else
		this->moveDown(2.5);

	if (this->animation->getAnimationDoneState())
	{
		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
		this->setPosCharacterY(posYFromLevel);
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
}

void Character::updateBackwardJump()
{
	int currentFrame = this->animation->getCurrentFrame();
	int maxFrame = this->animation->getAnimationData()->getSpriteNb();
	int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());
	
	if(this->toward == RIGHT)
	{
		this->moveLeft(2);
		this->endOfTheScreenReached = false;
		if(this->getPosCharacterX() <= 0)
		{
			this->setPosCharacterX(0);
			this->endOfTheScreenReached = true;
		}
	}
	else
	{
		this->moveRight(2);
		this->endOfTheScreenReached = false;
		if(this->getPosCharacterX() + spriteWidth >= SCREEN_SIZE_WIDTH)
		{
			this->setPosCharacterX(SCREEN_SIZE_WIDTH - spriteWidth);
			this->endOfTheScreenReached = true;
		}
	}

	if(currentFrame < maxFrame/2)
		this->moveUp(2);
	else
		this->moveDown(2);

	if (this->animation->getAnimationDoneState())
	{
		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
		this->setPosCharacterY(posYFromLevel);
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
}

void Character::updateGuard()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1) && this->endOfTheScreenReached)
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1) && this->endOfTheScreenReached)
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = CharacterState::STATE_CHARACTER_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateGuardOn()
{

	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1) && this->endOfTheScreenReached)
	{
		this->state = CharacterState::STATE_CHARACTER_GUARD_ON;
		this->updateAnimationCharacter();
	}
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1) && this->endOfTheScreenReached)
	{
		this->state = CharacterState::STATE_CHARACTER_GUARD_ON;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_LOW_GUARD_ON;
		this->updateAnimationCharacter();
	}
}

void Character::updateLowGuard()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = CharacterState::STATE_CHARACTER_LOW_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCHED;
		this->updateAnimationCharacter();
	}
}

void Character::updateLowGuardOn()
{
	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCHED;
		this->updateAnimationCharacter();
	}

	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_GUARD_ON;
		this->updateAnimationCharacter();
	}
}

void Character::updatePunch()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STAND;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch();
}

void Character::updateKick()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STAND;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch();
}

void Character::updateCrouchedKick()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCHED;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STANDUP;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch();
}

void Character::updateCrouchedPunch()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCHED;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STANDUP;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch();
}

void Character::updateJumpedPunch()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STAND;
		}

		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();

		this->updateAnimationCharacter();
		this->setPosCharacterY(posYFromLevel);
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch();
}

void Character::updateJumpedKick()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STAND;
		}

		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();

		this->updateAnimationCharacter();
		this->setPosCharacterY(posYFromLevel);
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch();
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
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
		{
			this->state = CharacterState::STATE_CHARACTER_CROUCHED;
		}
		else
		{
			this->state = CharacterState::STATE_CHARACTER_STANDUP;
		}
		this->updateAnimationCharacter();
	}
}

void Character::updateVictory()
{
	if (this->animation->getAnimationDoneState())
	{
		this->state = CharacterState::STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateCrouched()
{
	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_STANDUP;
		this->updateAnimationCharacter();
	}
	
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCHED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2, -1))
	{
		this->state = CharacterState::STATE_CHARACTER_CROUCHED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4, -1))
	{
		if (this->animation->getAnimationDoneState() || this->state == STATE_CHARACTER_CROUCHED)
		{
			this->state = CharacterState::STATE_CHARACTER_LOW_GUARD;
			this->updateAnimationCharacter();
		}
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

void Character::moveRight(double speedCoef)
{
	this->setPosCharacterX(this->getPosCharacterX() + speedCoef * MOVE_SPEED);
}

void Character::moveLeft(double speedCoef)
{
	this->setPosCharacterX(this->getPosCharacterX() - speedCoef * MOVE_SPEED);
}

void Character::moveUp(double speedCoef)
{
	this->setPosCharacterY(this->getPosCharacterY() - speedCoef * MOVE_SPEED);
}

void Character::moveDown(double speedCoef)
{
	this->setPosCharacterY(this->getPosCharacterY() + speedCoef * MOVE_SPEED);
}

void Character::updateAnimationCharacter()
{
	this->positionCharacter->setX(this->positionCharacter->getX() + this->animation->getAnimationData()->getShiftPositionXCharacter());
	this->animation->changeAnimation(this->state + this->toward * CharacterState::NUMBER_STATE_CHARACTER);
	this->positionCharacter->setX(this->positionCharacter->getX() - this->animation->getAnimationData()->getShiftPositionXCharacter());
	this->collider->changeColliderData(this->animation->getAnimationData()->getColliderID());
	this->colliderKickPunch->changeColliderData(this->animation->getAnimationData()->getColliderKickPunchID());
}

void Character::checkDirection()
{
	CharacterDirection currentDirection = this->toward;
	Character* closest = GameManager::getInstance()->getCharacterManager()->getClosestCharacter(this->indexCharacter, this->positionCharacter);

	if (closest != NULL)
	{
		if (this->positionCharacter->getX() - closest->getPosCharacterX() < 0)
		{
			if(currentDirection != CharacterDirection::RIGHT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = CharacterDirection::RIGHT;
					this->updateAnimationCharacter();
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
			}
		}
	}
}

void Character::hitCharacter(int damage)
{
	if (this->state != STATE_CHARACTER_GUARD && this->state != STATE_CHARACTER_GUARD_ON && this->state != STATE_CHARACTER_LOW_GUARD && this->state != STATE_CHARACTER_LOW_GUARD_ON)
	{
		this->hp -= damage;
		if (this->hp < 0)
			this->hp = 0;
		
		if (this->state == STATE_CHARACTER_CROUCH || this->state == STATE_CHARACTER_STANDUP || this->state == STATE_CHARACTER_CROUCHED_KICK ||
			this->state == STATE_CHARACTER_CROUCHED_PUNCH || this->state == STATE_CHARACTER_LOW_HIT || this->state == STATE_CHARACTER_CROUCHED)
			this->state = STATE_CHARACTER_LOW_HIT;
		else
			this->state = STATE_CHARACTER_HIT;

		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();

		this->updateAnimationCharacter();
		this->setPosCharacterY(posYFromLevel);
	}
}

void Character::updateKickPunch()
{
	// Update position kick
	if (this->colliderKickPunch->getPosition() != NULL)
	{
		Character * enemy = GameManager::getInstance()->getCharacterManager()->getClosestCharacter(this->indexCharacter, this->colliderKickPunch->getPosition());
		if (enemy != NULL && this->colliderKickPunch->AreColliding(enemy->getCollider()))
		{
			enemy->hitCharacter(this->damage);
			this->colliderKickPunch->setPosition(NULL);
			if (enemy->getHp() == 0)
			{
				this->state = CharacterState::STATE_CHARACTER_VICTORY;
				this->updateAnimationCharacter();
			}
		}
		else
		{
			double distance = this->colliderKickPunch->getColliderData()->getPosX();
			double speed = this->animation->getAnimationData()->getFramerate() * this->animation->getAnimationData()->getSpriteNb();
			if (this->toward == CharacterDirection::RIGHT && this->colliderKickPunch->getPosition()->getX() != this->positionCharacter->getX() + this->collider->getShiftX() + this->colliderKickPunch->getColliderData()->getPosX())
			{
				this->colliderKickPunch->getPosition()->setX(this->colliderKickPunch->getPosition()->getX() + distance / speed);
			}
			else if (this->toward == CharacterDirection::LEFT && this->colliderKickPunch->getPosition()->getX() != this->positionCharacter->getX() + this->collider->getShiftX() - this->colliderKickPunch->getColliderData()->getPosX())
			{
				this->colliderKickPunch->getPosition()->setX(this->colliderKickPunch->getPosition()->getX() - distance / speed);
			}
		}
	}
}