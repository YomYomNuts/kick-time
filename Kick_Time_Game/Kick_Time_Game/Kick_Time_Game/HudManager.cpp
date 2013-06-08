#include "HudManager.h"
#include "HudManager_Defines.h"
#include "GameManager.h"

HudManager::HudManager(void)
{
	this->doRenderLifeBar = true;
	this->doRenderTime = true;
	this->spriteHUD = new sf::Sprite();
}

HudManager::~HudManager(void)
{
}

void HudManager::initializeHudManager()
{
	this->spriteHUD->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(FILE_HUD));
}

void HudManager::updateHudManager()
{
}

void HudManager::renderHudManager()
{
	if (this->doRenderTime)
		this->renderTime();
	if (this->doRenderLifeBar)
	{
		for(int i = 0; i < NUMBER_FIGHTERS; ++i)
			this->renderLifeBar(i);
	}
}

void HudManager::renderLifeBar(int indexCharacter)
{
}

void HudManager::renderTime()
{
	if (GameManager::getInstance()->getMatchManager()->getActiveMatch() != NULL)
	{
		int timer = GameManager::getInstance()->getMatchManager()->getActiveMatch()->getTime();
		int shiftX;
		// First Number
		shiftX = ((int)(timer / 10) * TIME_WIDTH);
		this->spriteHUD->setTextureRect(sf::IntRect(TIME_X + shiftX, TIME_Y, TIME_WIDTH, TIME_HEIGHT));
		this->spriteHUD->setPosition(TIME_POSITION_1_X, TIME_POSITION_1_Y);
		GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteHUD);
		//Second Number
		shiftX = ((int)(timer % 10) * TIME_WIDTH);
		this->spriteHUD->setTextureRect(sf::IntRect(TIME_X + shiftX, TIME_Y, TIME_WIDTH, TIME_HEIGHT));
		this->spriteHUD->setPosition(TIME_POSITION_2_X, TIME_POSITION_2_Y);
		GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteHUD);
	}
}
