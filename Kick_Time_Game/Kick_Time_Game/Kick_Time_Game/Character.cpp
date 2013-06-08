#include "Character.h"
#include "Character_Defines.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"

#include <iostream>

Character::Character(void)
{
	this->state = STATE_CHARACTER_STAND;
	this->animation = new Animation(this->state);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->spriteCharacter = new sf::Sprite();
	this->posCharacterX = SCREEN_SIZE_WIDTH / 2;
	this->posCharacterY = SCREEN_SIZE_HEIGHT;
	this->totalHp = 100;
	this->hp = 50;
}

Character::~Character(void)
{
	delete this->animation;
}

void Character::updateCharacter()
{
	switch (this->state)
	{
	case STATE_CHARACTER_STAND:
		break;
	case STATE_CHARACTER_VICTORY:
		break;
	case STATE_CHARACTER_FORWARD:
		break;
	case STATE_CHARACTER_BACKWARD:
		break;
	case STATE_CHARACTER_STOOP:
		break;
	case STATE_CHARACTER_PICKUP:
		break;
	case STATE_CHARACTER_PUNCHRIGHT:
		break;
	case STATE_CHARACTER_PUNCHLEFT:
		break;
	case STATE_CHARACTER_KICKRIGHT:
		break;
	case STATE_CHARACTER_KICKLEFT:
		break;
	case STATE_CHARACTER_KICKJUMP:
		break;
	case STATE_CHARACTER_KICKDOWN:
		break;
	case STATE_CHARACTER_BLOCKING:
		break;
	case STATE_CHARACTER_BLOCKINGDOWN:
		break;
	case STATE_CHARACTER_HIT:
		break;
	case STATE_CHARACTER_HITDOWN:
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

int Character::getTotalHp()
{
	return this->totalHp;
}

int Character::getHp()
{
	return this->hp;
}