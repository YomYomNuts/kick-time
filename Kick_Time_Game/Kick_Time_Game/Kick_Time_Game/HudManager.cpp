#include "HudManager.h"
#include "HudManager_Defines.h"
#include "GameManager.h"


const Position listPositions[NUMBER_FIGHTERS] = { Position(LIFE_BAR_POSITION_P1_X, LIFE_BAR_POSITION_P1_Y), Position(LIFE_BAR_POSITION_P2_X, LIFE_BAR_POSITION_P2_Y)};

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
		this->renderLifeBar();
}

void HudManager::renderLifeBar()
{
	vector<Character*> * listCharacters = GameManager::getInstance()->getCharacterManager()->getCharacters();
	Character * character;
	int percent;
	for(unsigned int i = 0; i < listCharacters->size(); ++i)
	{
		character = listCharacters->at(i);
		percent = (int)((LIFE_WIDTH * character->getHp()) / character->getTotalHp());
		// Empty life bar
		this->spriteHUD->setTextureRect(sf::IntRect(LIFE_BAR_X, LIFE_BAR_Y, LIFE_BAR_WIDTH, LIFE_BAR_HEIGHT));
		this->spriteHUD->setPosition((float)listPositions[i].getX(), (float)listPositions[i].getY());
		GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteHUD);

		if (i % 2 == 0)
		{
			//Life
			this->spriteHUD->setTextureRect(sf::IntRect(LIFE_X, LIFE_Y, percent, LIFE_HEIGHT));
			this->spriteHUD->setPosition((float)listPositions[i].getX() + LIFE_FRAME_SIZE_X, (float)listPositions[i].getY() + LIFE_FRAME_SIZE_Y);
			GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteHUD);

			//Name
			this->spriteHUD->setTextureRect(sf::IntRect(LIFE_X, LIFE_Y, percent, LIFE_HEIGHT));
			this->spriteHUD->setPosition((float)listPositions[i].getX() + LIFE_FRAME_SIZE_X, (float)listPositions[i].getY() + LIFE_FRAME_SIZE_Y);
			GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteHUD);
		}
		else
		{
			//Life
			this->spriteHUD->setTextureRect(sf::IntRect(LIFE_X, LIFE_Y, percent, LIFE_HEIGHT));
			this->spriteHUD->setPosition((float)listPositions[i].getX() + LIFE_FRAME_SIZE_X + LIFE_WIDTH - percent, (float)listPositions[i].getY() + LIFE_FRAME_SIZE_Y);
			GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteHUD);
		}
	}
}

void HudManager::renderTime()
{
	Level * level = GameManager::getInstance()->getLevelManager()->getActiveLevel();
	if (level != NULL)
	{
		int timer = level->getTime();
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
