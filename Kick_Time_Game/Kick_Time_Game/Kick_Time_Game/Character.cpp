#include "Character.h"
#include "Character_Defines.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"

#include <iostream>

Character::Character(void)
{
	this->spriteCharacter = new sf::Sprite();
	this->state = STATE_CHARACTER_STAND;
	this->animation = new Animation(this->state);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->collider = new Collider(this->animation->getAnimationData()->getColliderID());
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
	case STATE_CHARACTER_STAND:
		this->updateStand();
		break;
	case STATE_CHARACTER_FORWARD:
		this->updateForward();
		break;
	case STATE_CHARACTER_BACKWARD:
		this->updateBackward();
		break;
	case STATE_CHARACTER_CROUCH:
		this->updateCrouch();
		break;
	case STATE_CHARACTER_STANDUP:
		this->updateStandUp();
		break;
	case STATE_CHARACTER_STEADY_JUMP:
		this->updateSteadyJump();
		break;
	case STATE_CHARACTER_FORWARD_JUMP:
		this->updateForwardJump();
		break;
	case STATE_CHARACTER_GUARD:
		this->updateGuard();
		break;
	case STATE_CHARACTER_LOW_GUARD:
		this->updateLowGuard();
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
	}
}

void Character::updateStand()
{
}

void Character::updateForward()
{
}

void Character::updateBackward()
{
}

void Character::updateCrouch()
{
}

void Character::updateStandUp()
{
}

void Character::updateSteadyJump()
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

void Character::renderCharacter()
{
	int posX = this->animation->getPosX();
	int posY = this->animation->getAnimationData()->getPosY();
	int width = this->animation->getAnimationData()->getSpriteWidth();
	int height = this->animation->getAnimationData()->getSpriteHeight();

	this->spriteCharacter->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->animation->getAnimationData()->getFileName()));
	this->spriteCharacter->setTextureRect(sf::IntRect(posX, posY, width, height));
	this->spriteCharacter->setPosition((float)this->posCharacterX, (float)this->posCharacterY - height);

	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteCharacter);

	// Debug collider
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f((float)this->collider->getColliderData()->getHalfSizeX()*2, (float)this->collider->getColliderData()->getHalfSizeY()*2));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition((float)this->posCharacterX + this->collider->getColliderData()->getPosX(), (float)this->posCharacterY - height + this->collider->getColliderData()->getPosY());
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(rectangle);
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
	if(this->toward == RIGHT)
		this->setPosCharacterX(this->getPosCharacterX() + MOVE_SPEED);
	else
		this->setPosCharacterX(this->getPosCharacterX() - MOVE_SPEED);
}

void Character::moveBackward()
{
	if(this->toward == RIGHT)
		this->setPosCharacterX(this->getPosCharacterX() - MOVE_SPEED);
	else
		this->setPosCharacterX(this->getPosCharacterX() + MOVE_SPEED);
}