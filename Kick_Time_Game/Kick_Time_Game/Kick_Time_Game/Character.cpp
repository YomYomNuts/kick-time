#include "Character.h"
#include "TextureManager.h"
#include "GameManager_Defines.h"
#include "GameManager.h"
#include <iostream>

Character::Character(void)
{
	this->animation = new Animation(0);
	GameManager::getInstance()->getAnimationManager()->addAnimation(this->animation);
	this->spriteCharacter = new sf::Sprite();
	this->posCharacterX = SCREEN_SIZE_WIDTH / 2;
	this->posCharacterY = SCREEN_SIZE_HEIGHT;
}

Character::~Character(void)
{
	delete this->animation;
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