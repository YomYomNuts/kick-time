#include "Character.h"
#include "Character_Defines.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"
#include "Debug.h"


Character::Character(void)
{
	double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
	this->indexCharacter = 0;
	if(this->indexCharacter % 2 == 0)
		this->toward = CHARACTER_DIRECTION_RIGHT;
	else
		this->toward = CHARACTER_DIRECTION_LEFT;

	this->characterData = &characterDataArray[0];
	this->spriteCharacter = new sf::Sprite();
	this->state = STATE_CHARACTER_STAND;
	this->animation = new AnimationCharacter(this->characterData->getAnimationID() + this->state + this->toward * NUMBER_STATE_CHARACTER);
	GameManager::getInstance()->getAnimationManager()->addCharacterAnimation(this->animation);
	this->positionCharacter = new Position(SCREEN_SIZE_WIDTH / 2 - this->animation->getAnimationData()->getShiftPositionXCharacter(), posYFromLevel);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID(), this->positionCharacter);
	this->colliderKickPunch = new Collider();
	this->totalHp = this->characterData->getTotalHP();
	this->hp = this->totalHp;
	this->endOfScreenReached = false;
	this->numberRoundWin = 0;
	this->completelyDead = false;
}

Character::Character(int indexCharacter, int indexTypeCharacter)
{
	double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
	double posX = SCREEN_SIZE_WIDTH / 2;

	this->indexCharacter = indexCharacter;
	if(this->indexCharacter % 2 == 0)
	{
		this->toward = CHARACTER_DIRECTION_RIGHT;
		posX -= SHIFT_BETWEEN_CHARACTERS;
	}
	else
	{
		this->toward = CHARACTER_DIRECTION_LEFT;
		posX += SHIFT_BETWEEN_CHARACTERS;
	}

	this->characterData = &characterDataArray[indexTypeCharacter];
	this->spriteCharacter = new sf::Sprite();
	this->state = STATE_CHARACTER_STAND;
	this->animation = new AnimationCharacter(this->characterData->getAnimationID() + this->state + this->toward * NUMBER_STATE_CHARACTER);
	GameManager::getInstance()->getAnimationManager()->addCharacterAnimation(this->animation);
	this->positionCharacter = new Position(posX - this->animation->getAnimationData()->getShiftPositionXCharacter(), posYFromLevel);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID(), this->positionCharacter);
	this->colliderKickPunch = new Collider();
	this->totalHp = this->characterData->getTotalHP();
	this->hp = this->totalHp;
	this->endOfScreenReached = false;
	this->numberRoundWin = 0;
}

Character::~Character(void)
{
	delete this->spriteCharacter;
	delete this->animation;
	delete this->collider;
	delete this->positionCharacter;
	delete this->colliderKickPunch;
	delete this->characterData;
}

AnimationCharacter* Character::getAnimation()
{
	return animation;
}

void Character::updateCharacter()
{
	Level * level = GameManager::getInstance()->getLevelManager()->getActiveLevel();
	if (level != NULL && level->getLevelState() == STATE_LEVEL_ROUND)
	{
		switch (this->state)
		{
		case STATE_CHARACTER_STAND:
			this->updateStand();
			break;
		case STATE_CHARACTER_MOVE_RIGHT:
			this->updateMoveRight();
			break;
		case STATE_CHARACTER_MOVE_LEFT:
			this->updateMoveLeft();
			break;
		case STATE_CHARACTER_CROUCH:
			this->updateCrouch();
			break;
		case STATE_CHARACTER_STANDUP:
			this->updateStandUp();
			break;
		case STATE_CHARACTER_STEADY_JUMP_UP:
			this->updateSteadyJumpUp();
			break;
		case STATE_CHARACTER_STEADY_JUMP_DOWN:
			this->updateSteadyJumpDown();
			break;
		case STATE_CHARACTER_FORWARD_JUMP:
			this->updateForwardJump();
			break;
		case STATE_CHARACTER_BACKWARD_JUMP:
			this->updateBackwardJump();
			break;
		case STATE_CHARACTER_GUARD:
			this->updateGuard();
			break;
		case STATE_CHARACTER_GUARD_ON:
			this->updateGuardOn();
			break;
		case STATE_CHARACTER_LOW_GUARD:
			this->updateLowGuard();
			break;
		case STATE_CHARACTER_LOW_GUARD_ON:
			this->updateLowGuardOn();
			break;
		case STATE_CHARACTER_PUNCH:
			this->updatePunch();
			break;
		case STATE_CHARACTER_KICK:
			this->updateKick();
			break;
		case STATE_CHARACTER_CROUCHED_KICK:
			this->updateCrouchedKick();
			break;
		case STATE_CHARACTER_CROUCHED_PUNCH:
			this->updateCrouchedPunch();
			break;
		case STATE_CHARACTER_JUMPED_PUNCH:
			this->updateJumpedPunch();
			break;
		case STATE_CHARACTER_JUMPED_KICK:
			this->updateJumpedKick();
			break;
		case STATE_CHARACTER_HIT:
			this->updateHit();
			break;
		case STATE_CHARACTER_LOW_HIT:
			this->updateLowHit();
			break;
		case STATE_CHARACTER_VICTORY:
			this->updateVictory();
			break;
		case STATE_CHARACTER_CROUCHED:
			this->updateCrouched();
			break;
        default:
            break;
		}
	}
}

void Character::updateStand()
{
	this->checkDirection();
	//this->endOfScreenReached = false;

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
	{
		this->state = STATE_CHARACTER_MOVE_RIGHT;
		this->updateAnimationCharacter();
		this->moveRight(1);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
	{
		this->state = STATE_CHARACTER_MOVE_LEFT;
		this->updateAnimationCharacter();
		this->moveLeft(1);
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		this->state = STATE_CHARACTER_CROUCH;
		this->updateAnimationCharacter();
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP))
	{
		this->state = STATE_CHARACTER_STEADY_JUMP_UP;
		this->updateAnimationCharacter();
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1))
	{
		this->state = STATE_CHARACTER_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundKick());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2))
	{
		this->state = STATE_CHARACTER_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundPunch());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
	{
		this->state = STATE_CHARACTER_GUARD;
		this->updateAnimationCharacter();
	}
}

void Character::updateMoveRight()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
	{

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP) && this->toward == CHARACTER_DIRECTION_RIGHT)
		{
			this->state = STATE_CHARACTER_FORWARD_JUMP;
			this->updateAnimationCharacter();
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP) && this->toward == CHARACTER_DIRECTION_LEFT)
		{
			this->state = STATE_CHARACTER_BACKWARD_JUMP;
			this->updateAnimationCharacter();
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
		{
			this->state = STATE_CHARACTER_GUARD;
			this->updateAnimationCharacter();
		}

		int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());

		this->moveRight(1.5);

		if(this->getPosCharacterX() + spriteWidth >= SCREEN_SIZE_WIDTH)
		{
			double levelWidth = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getSpriteLevel()->getTexture()->getSize().x;
			double posXlevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();

			// if the right corner of the level is higher than the screen size
			if(posXlevel + levelWidth > SCREEN_SIZE_WIDTH)
			{
				// Move the farest character
				Character* farest = GameManager::getInstance()->getCharacterManager()->getFarestCharacter(this->indexCharacter, this->positionCharacter);

				if(farest != NULL)
				{
					// IF the enemy is on th edge of the screen
					if(farest->getPosCharacterX() <= 0)
					{
						farest->setPosCharacterX(0);
						this->state = STATE_CHARACTER_GUARD;
						this->updateAnimationCharacter();
					}
					else
					{
						if(farest->getCharacterState() == STATE_CHARACTER_FORWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_BACKWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_RIGHT ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_LEFT)
						{
							farest->moveLeft(1.5);
						}
						else
						{
							farest->moveLeft(0.75);
						}

						if(!GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfLevelReachedState())
						{
							// Move the level
							double posXLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();
							GameManager::getInstance()->getLevelManager()->getActiveLevel()->setPosX(posXLevel - 1.5);
						}
					}
				}

			}
			else
			{
				GameManager::getInstance()->getLevelManager()->getActiveLevel()->setEndOfLevelReachedState(false);
				this->state = STATE_CHARACTER_GUARD;
				this->updateAnimationCharacter();
			}
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
	{
		this->moveLeft(1.5);

		this->state = STATE_CHARACTER_MOVE_LEFT;
		this->updateAnimationCharacter();

	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		this->state = STATE_CHARACTER_CROUCH;
		this->updateAnimationCharacter();
	}
	else
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateMoveLeft()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
	{
		this->moveRight(1.5);

		this->state = STATE_CHARACTER_MOVE_RIGHT;
		this->updateAnimationCharacter();

	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP) && this->toward == CHARACTER_DIRECTION_LEFT)
		{
			this->state = STATE_CHARACTER_FORWARD_JUMP;
			this->updateAnimationCharacter();
			GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_UP) && this->toward == CHARACTER_DIRECTION_RIGHT)
		{
			this->state = STATE_CHARACTER_BACKWARD_JUMP;
			this->updateAnimationCharacter();
			GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		}

		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
		{
			this->state = STATE_CHARACTER_GUARD;
			this->updateAnimationCharacter();
		}

		//Get the farest character
		Character* farest = GameManager::getInstance()->getCharacterManager()->getFarestCharacter(this->indexCharacter, this->positionCharacter);

		this->moveLeft(1.5);

		// The character has reached the edge of the screen
		if(this->getPosCharacterX() <= 0)
		{
			this->endOfScreenReached = true;

			// if the left corner of the level is under 0
			if(GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX() < 0)
			{
				// Move the farest character
				if(farest != NULL)
				{
					int enemySpriteWidth = abs(farest->getAnimation()->getAnimationData()->getSpriteWidth());

					// IF the enemy is on th edge of the screen
					if(farest->getPosCharacterX() + enemySpriteWidth >= SCREEN_SIZE_WIDTH)
					{
						this->state = STATE_CHARACTER_GUARD;
						this->setPosCharacterX(0);
						this->updateAnimationCharacter();
					}
					else
					{
						if(farest->getCharacterState() == STATE_CHARACTER_FORWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_BACKWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_RIGHT ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_LEFT)
						{
							farest->moveRight(1.5);
						}
						else
						{
							farest->moveRight(0.75);
						}

						if(!GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfLevelReachedState())
						{
							// Move the level
							double posXLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();
							GameManager::getInstance()->getLevelManager()->getActiveLevel()->setPosX(posXLevel + 1.5);
						}
					}
				}

			}
			else
			{
				GameManager::getInstance()->getLevelManager()->getActiveLevel()->setEndOfLevelReachedState(false);
				this->state = STATE_CHARACTER_GUARD;
				this->updateAnimationCharacter();
			}
		}
		else
		{
			this->endOfScreenReached = false;
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		this->state = STATE_CHARACTER_CROUCH;
		this->updateAnimationCharacter();
	}
	else
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateCrouch()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = STATE_CHARACTER_CROUCHED;
			this->updateAnimationCharacter();
		}
	}
	else
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateStandUp()
{
	this->checkDirection();

	if (this->animation->getAnimationDoneState())
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateSteadyJumpUp()
{
	this->checkDirection();

	this->moveUp(2);
	if (this->animation->getAnimationDoneState())
	{
		this->state = STATE_CHARACTER_STEADY_JUMP_DOWN;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1))
	{
		this->state = STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundKick());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2))
	{
		this->state = STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundPunch());
	}
}

void Character::updateSteadyJumpDown()
{
	this->checkDirection();

	this->moveDown(2);

	if (this->animation->getAnimationDoneState())
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1))
	{
		this->state = STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundKick());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2))
	{
		this->state = STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundJump());
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundPunch());
	}
}

void Character::updateForwardJump()
{
	int currentFrame = this->animation->getCurrentFrame();
	int maxFrame = this->animation->getAnimationData()->getSpriteNb();
	int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());

	if(this->toward == CHARACTER_DIRECTION_RIGHT)
	{
		this->moveRight(2);

		if(this->getPosCharacterX() + spriteWidth >= SCREEN_SIZE_WIDTH)
		{
			double levelWidth = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getSpriteLevel()->getTexture()->getSize().x;
			double posXlevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();

			// if the right corner of the level is higher than the screen size
			if(posXlevel + levelWidth >= SCREEN_SIZE_WIDTH)
			{
				// Move the farest character
				Character* farest = GameManager::getInstance()->getCharacterManager()->getFarestCharacter(this->indexCharacter, this->positionCharacter);

				if(farest != NULL)
				{
					// IF the enemy is on the edge of the screen
					if(farest->getPosCharacterX() <= 0)
					{
						farest->setPosCharacterX(0);
					}
					else
					{
						if(farest->getCharacterState() == STATE_CHARACTER_FORWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_BACKWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_RIGHT ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_LEFT)
						{
							farest->moveLeft(2);
						}
						else
						{
							farest->moveLeft(1);
						}

						if(!GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfLevelReachedState())
						{
							// Move the level
							double posXLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();
							GameManager::getInstance()->getLevelManager()->getActiveLevel()->setPosX(posXLevel - 1.5);
						}
					}
				}
			}
			else
			{
				GameManager::getInstance()->getLevelManager()->getActiveLevel()->setEndOfLevelReachedState(false);
			}
		}
	}
	else
	{
		this->moveLeft(2);

		if(this->getPosCharacterX() <= 0)
		{

			// if the left corner of the level is under 0
			if(GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX() < 0)
			{
				// Move the farest character
				Character* farest = GameManager::getInstance()->getCharacterManager()->getFarestCharacter(this->indexCharacter, this->positionCharacter);

				if(farest != NULL)
				{
					int enemySpriteWidth = abs(farest->getAnimation()->getAnimationData()->getSpriteWidth());

					// IF the enemy is on th edge of the screen
					if(farest->getPosCharacterX() + enemySpriteWidth >= SCREEN_SIZE_WIDTH)
					{
						this->setPosCharacterX(0);
					}
					else
					{
						if(farest->getCharacterState() == STATE_CHARACTER_FORWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_BACKWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_RIGHT ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_LEFT)
						{
							farest->moveRight(2);
						}
						else
						{
							farest->moveRight(1);
						}

						if(!GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfLevelReachedState())
						{
							// Move the level
							double posXLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();
							GameManager::getInstance()->getLevelManager()->getActiveLevel()->setPosX(posXLevel + 1.5);
						}
					}
				}
			}
			else
			{
				GameManager::getInstance()->getLevelManager()->getActiveLevel()->setEndOfLevelReachedState(false);
			}
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
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1))
	{
		this->state = STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundKick());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2))
	{
		this->state = STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundPunch());
	}
}

void Character::updateBackwardJump()
{
	int currentFrame = this->animation->getCurrentFrame();
	int maxFrame = this->animation->getAnimationData()->getSpriteNb();
	int spriteWidth = abs(this->getAnimation()->getAnimationData()->getSpriteWidth());

	if(this->toward == CHARACTER_DIRECTION_RIGHT)
	{
		this->moveLeft(2);

		if(this->getPosCharacterX() <= 0)
		{

			// if the left corner of the level is under 0
			if(GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX() < 0)
			{
				// Move the farest character
				Character* farest = GameManager::getInstance()->getCharacterManager()->getFarestCharacter(this->indexCharacter, this->positionCharacter);

				if(farest != NULL)
				{
					int enemySpriteWidth = abs(farest->getAnimation()->getAnimationData()->getSpriteWidth());

					// IF the enemy is on th edge of the screen
					if(farest->getPosCharacterX() + enemySpriteWidth >= SCREEN_SIZE_WIDTH)
					{
						this->setPosCharacterX(0);
					}
					else
					{
						if(farest->getCharacterState() == STATE_CHARACTER_FORWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_BACKWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_RIGHT ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_LEFT)
						{
							farest->moveRight(2);
						}
						else
						{
							farest->moveRight(1);
						}

						if(!GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfLevelReachedState())
						{
							// Move the level
							double posXLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();
							GameManager::getInstance()->getLevelManager()->getActiveLevel()->setPosX(posXLevel + 1.5);
						}
					}
				}

			}
			else
			{
				GameManager::getInstance()->getLevelManager()->getActiveLevel()->setEndOfLevelReachedState(false);
			}
		}
	}
	else
	{
		this->moveRight(2);

		if(this->getPosCharacterX() + spriteWidth >= SCREEN_SIZE_WIDTH)
		{
			double levelWidth = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getSpriteLevel()->getTexture()->getSize().x;
			double posXlevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();


			// if the right corner of the level is higher than the screen size
			if(posXlevel + levelWidth > SCREEN_SIZE_WIDTH)
			{
				// Move the farest character
				Character* farest = GameManager::getInstance()->getCharacterManager()->getFarestCharacter(this->indexCharacter, this->positionCharacter);

				if(farest != NULL)
				{
					// IF the enemy is on the edge of the screen
					if(farest->getPosCharacterX() <= 0)
					{
						farest->setPosCharacterX(0);
					}
					else
					{
						if(farest->getCharacterState() == STATE_CHARACTER_FORWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_BACKWARD_JUMP ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_RIGHT ||
							farest->getCharacterState() == STATE_CHARACTER_MOVE_LEFT)
						{
							farest->moveLeft(2);
						}
						else
						{
							farest->moveLeft(1);
						}

						if(!GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfLevelReachedState())
						{
							// Move the level
							double posXLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getPosition()->getX();
							GameManager::getInstance()->getLevelManager()->getActiveLevel()->setPosX(posXLevel - 1.5);
						}
					}
				}
			}
			else
			{
				GameManager::getInstance()->getLevelManager()->getActiveLevel()->setEndOfLevelReachedState(false);
			}
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
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1))
	{
		this->state = STATE_CHARACTER_JUMPED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundKick());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2))
	{
		this->state = STATE_CHARACTER_JUMPED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundPunch());
	}
}

void Character::updateGuard()
{
	this->checkDirection();
	//bool endOfScreenState = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfScreenReachedState();
	bool endOfScreenState = this->endOfScreenReached;

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = STATE_CHARACTER_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT) && endOfScreenState)
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = STATE_CHARACTER_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT) && endOfScreenState)
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = STATE_CHARACTER_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateGuardOn()
{
	//bool endOfScreenState = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getEndOfScreenReachedState();
	bool endOfScreenState = this->endOfScreenReached;

	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT) && endOfScreenState)
	{
		this->state = STATE_CHARACTER_GUARD_ON;
		this->updateAnimationCharacter();
	}
	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT) && endOfScreenState)
	{
		this->state = STATE_CHARACTER_GUARD_ON;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		this->state = STATE_CHARACTER_LOW_GUARD_ON;
		this->updateAnimationCharacter();
	}
}

void Character::updateLowGuard()
{
	this->checkDirection();

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
	{
		if (this->animation->getAnimationDoneState())
		{
			this->state = STATE_CHARACTER_LOW_GUARD_ON;
			this->updateAnimationCharacter();
		}
	}
	else
	{
		this->state = STATE_CHARACTER_CROUCHED;
		this->updateAnimationCharacter();
	}
}

void Character::updateLowGuardOn()
{
	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
	{
		this->state = STATE_CHARACTER_CROUCHED;
		this->updateAnimationCharacter();
	}

	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		this->state = STATE_CHARACTER_GUARD_ON;
		this->updateAnimationCharacter();
	}
}

void Character::updatePunch()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
		{
			this->state = STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
		{
			this->state = STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = STATE_CHARACTER_STAND;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch(this->characterData->getDamagePunch(), this->characterData->getSpeedPunch());
}

void Character::updateKick()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
		{
			this->state = STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
		{
			this->state = STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = STATE_CHARACTER_STAND;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch(this->characterData->getDamageKick(), this->characterData->getSpeedKick());
}

void Character::updateCrouchedKick()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCHED;
		}
		else
		{
			this->state = STATE_CHARACTER_STANDUP;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch(this->characterData->getDamageKickCrouch(), this->characterData->getSpeedKickCrouch());
}

void Character::updateCrouchedPunch()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCHED;
		}
		else
		{
			this->state = STATE_CHARACTER_STANDUP;
		}
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch(this->characterData->getDamagePunchCrouch(), this->characterData->getSpeedPunchCrouch());
}

void Character::updateJumpedPunch()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
		{
			this->state = STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
		{
			this->state = STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = STATE_CHARACTER_STAND;
		}

		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();

		this->updateAnimationCharacter();
		this->setPosCharacterY(posYFromLevel);
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch(this->characterData->getDamageKickCrouch(), this->characterData->getSpeedPunchJumped());
}

void Character::updateJumpedKick()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_RIGHT))
		{
			this->state = STATE_CHARACTER_MOVE_RIGHT;
			this->moveRight(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_LEFT))
		{
			this->state = STATE_CHARACTER_MOVE_LEFT;
			this->moveLeft(1);
		}
		else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCH;
		}
		else
		{
			this->state = STATE_CHARACTER_STAND;
		}

		double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();

		this->updateAnimationCharacter();
		this->setPosCharacterY(posYFromLevel);
		this->colliderKickPunch->setPosition(NULL);
	}
	this->updateKickPunch(this->characterData->getDamageKickJumped(), this->characterData->getSpeedKickJumped());
}

void Character::updateHit()
{
	if (this->animation->getAnimationDoneState())
	{
		this->state = STATE_CHARACTER_STAND;
		this->updateAnimationCharacter();
	}
}

void Character::updateLowHit()
{
	if (this->animation->getAnimationDoneState())
	{
		if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
		{
			this->state = STATE_CHARACTER_CROUCHED;
		}
		else
		{
			this->state = STATE_CHARACTER_STANDUP;
		}
		this->updateAnimationCharacter();
	}
}

void Character::updateVictory()
{
}

void Character::updateCrouched()
{
	if (!GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_MOVE_DOWN))
	{
		this->state = STATE_CHARACTER_STANDUP;
		this->updateAnimationCharacter();
	}

	if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_1))
	{
		this->state = STATE_CHARACTER_CROUCHED_KICK;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundKick());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_2))
	{
		this->state = STATE_CHARACTER_CROUCHED_PUNCH;
		this->updateAnimationCharacter();
		this->colliderKickPunch->setPosition(new Position(this->positionCharacter->getX() + this->collider->getShiftX(), this->positionCharacter->getY()));
		this->colliderKickPunch->setShiftX(0);
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundPunch());
	}
	else if (GameManager::getInstance()->getInputManager()->isPressed(this->indexCharacter, POSITION_INPUT_ACTION_4))
	{
		if (this->animation->getAnimationDoneState() || this->state == STATE_CHARACTER_CROUCHED)
		{
			this->state = STATE_CHARACTER_LOW_GUARD;
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
	this->endOfScreenReached = false;

	if(this->getPosCharacterX() > SCREEN_SIZE_WIDTH - abs(this->getAnimation()->getAnimationData()->getSpriteWidth()))
	{
		this->setPosCharacterX(SCREEN_SIZE_WIDTH - abs(this->getAnimation()->getAnimationData()->getSpriteWidth()));
		this->endOfScreenReached = true;
	}

}

void Character::moveLeft(double speedCoef)
{
	this->setPosCharacterX(this->getPosCharacterX() - speedCoef * MOVE_SPEED);
	this->endOfScreenReached = false;

	if(this->getPosCharacterX() < 0)
	{
		this->setPosCharacterX(0);
		this->endOfScreenReached = true;
	}
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
	this->animation->changeAnimation(this->state + this->toward * NUMBER_STATE_CHARACTER);
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
			if(currentDirection != CHARACTER_DIRECTION_RIGHT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = CHARACTER_DIRECTION_RIGHT;
					this->updateAnimationCharacter();
				}
			}
		}
		else
		{
			if(currentDirection != CHARACTER_DIRECTION_LEFT)
			{
				if(this->animation->getAnimationData()->getAnimationLoop() == true)
				{
					this->toward = CHARACTER_DIRECTION_LEFT;
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
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundHit());
	}
	else
	{
		GameManager::getInstance()->getSoundManager()->playSoundMusic(this->characterData->getSoundGuard());
	}
}

void Character::updateKickPunch(int damage, int speed)
{
	// Update position kick
	if (this->colliderKickPunch->getPosition() != NULL)
	{
		Character * enemy = GameManager::getInstance()->getCharacterManager()->getClosestCharacter(this->indexCharacter, this->colliderKickPunch->getPosition());
		if (enemy != NULL && this->colliderKickPunch->AreColliding(enemy->getCollider()))
		{
			enemy->hitCharacter(damage);
			this->colliderKickPunch->setPosition(NULL);
			if (enemy->getHp() == 0)
			{
				GameManager * gameManager = GameManager::getInstance();
				Level * level = gameManager->getLevelManager()->getActiveLevel();
				if (level != NULL)
				{
					double posYFromLevel = level->getLevelData()->getPosYCharacter();
					this->state = STATE_CHARACTER_VICTORY;
					this->updateAnimationCharacter();
					this->setPosCharacterY(posYFromLevel);
					gameManager->getSoundManager()->playSoundMusic(this->characterData->getSoundVictory());
					++this->numberRoundWin;
					level->nextStateLevel(this);
				}
			}
		}
		else
		{
			double distance = this->colliderKickPunch->getColliderData()->getPosX();
			if (this->toward == CHARACTER_DIRECTION_RIGHT && this->colliderKickPunch->getPosition()->getX() != this->positionCharacter->getX() + this->collider->getShiftX() + this->colliderKickPunch->getColliderData()->getPosX())
			{
				this->colliderKickPunch->getPosition()->setX(this->colliderKickPunch->getPosition()->getX() + (distance * 100 / speed) / 100);
			}
			else if (this->toward == CHARACTER_DIRECTION_LEFT && this->colliderKickPunch->getPosition()->getX() != this->positionCharacter->getX() + this->collider->getShiftX() - this->colliderKickPunch->getColliderData()->getPosX())
			{
				this->colliderKickPunch->getPosition()->setX(this->colliderKickPunch->getPosition()->getX() - (distance * 100 / speed) / 100);
			}
		}
	}
}

bool Character::getEndOfScreenReachedState()
{
	return this->endOfScreenReached;
}

CharacterState Character::getCharacterState()
{
	return state;
}

const CharacterData* Character::getCharacterData()
{
	return this->characterData;
}

void Character::setNumberRoundWin(int numberRoundWin)
{
	this->numberRoundWin = numberRoundWin;
}

int Character::getNumberRoundWin()
{
	return this->numberRoundWin;
}

void Character::restoreHp(int hp)
{
	if (hp > this->hp)
		this->hp = hp;
}

void Character::resetInformations()
{
	double posYFromLevel = GameManager::getInstance()->getLevelManager()->getActiveLevel()->getLevelData()->getPosYCharacter();
	double posX = SCREEN_SIZE_WIDTH / 2;

	if(this->indexCharacter % 2 == 0)
	{
		this->toward = CHARACTER_DIRECTION_RIGHT;
		posX -= SHIFT_BETWEEN_CHARACTERS;
	}
	else
	{
		this->toward = CHARACTER_DIRECTION_LEFT;
		posX += SHIFT_BETWEEN_CHARACTERS;
	}

	this->state = STATE_CHARACTER_STAND;
	this->updateAnimationCharacter();
	this->positionCharacter->setX(posX - this->animation->getAnimationData()->getShiftPositionXCharacter());
	this->positionCharacter->setY(posYFromLevel);
	this->endOfScreenReached = false;
}
