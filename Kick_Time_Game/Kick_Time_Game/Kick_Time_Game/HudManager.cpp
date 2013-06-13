#include "HudManager.h"
#include "HudManager_Defines.h"
#include "GameManager.h"
#include "FontData.h"


const Position listPositionsLifeBar[NUMBER_FIGHTERS] = {
	Position(LIFE_BAR_POSITION_P1_X, LIFE_BAR_POSITION_P1_Y),
	Position(LIFE_BAR_POSITION_P2_X, LIFE_BAR_POSITION_P2_Y)
};

const Position listPositionsName[NUMBER_FIGHTERS] = {
	Position(NAME_POSITION_P1_X, NAME_POSITION_P1_Y),
	Position(NAME_POSITION_P2_X, NAME_POSITION_P2_Y)
};

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
	GameManager * gameManager = GameManager::getInstance();

	for(unsigned int i = 0; i < listCharacters->size(); ++i)
	{
		character = listCharacters->at(i);
		percent = (int)((LIFE_WIDTH * character->getHp()) / character->getTotalHp());
		// Empty life bar
		this->spriteHUD->setTextureRect(sf::IntRect(LIFE_BAR_X, LIFE_BAR_Y, LIFE_BAR_WIDTH, LIFE_BAR_HEIGHT));
		this->spriteHUD->setPosition((float)listPositionsLifeBar[i].getX(), (float)listPositionsLifeBar[i].getY());
		gameManager->getRenderManager()->getWindow()->draw(*this->spriteHUD);

		if (i % 2 == 0)
		{
			//Life
			this->spriteHUD->setTextureRect(sf::IntRect(LIFE_X, LIFE_Y, percent, LIFE_HEIGHT));
			this->spriteHUD->setPosition((float)listPositionsLifeBar[i].getX() + LIFE_FRAME_SIZE_X, (float)listPositionsLifeBar[i].getY() + LIFE_FRAME_SIZE_Y);
			gameManager->getRenderManager()->getWindow()->draw(*this->spriteHUD);

			//Name
			sf::Text text(character->getCharacterData()->getName(), *(gameManager->getFontManager()->getFont(FONT_ARIAL)));
			text.setColor(sf::Color(NAME_COLOR_RED, NAME_COLOR_GREEN, NAME_COLOR_BLUE));
			text.setScale((float)NAME_SCALE_X, (float)NAME_SCALE_Y);
			text.setPosition((float)listPositionsName[i].getX(), (float)listPositionsName[i].getY());
			gameManager->getRenderManager()->getWindow()->draw(text);
		}
		else
		{
			//Life
			this->spriteHUD->setTextureRect(sf::IntRect(LIFE_X, LIFE_Y, percent, LIFE_HEIGHT));
			this->spriteHUD->setPosition((float)listPositionsLifeBar[i].getX() + LIFE_FRAME_SIZE_X + LIFE_WIDTH - percent, (float)listPositionsLifeBar[i].getY() + LIFE_FRAME_SIZE_Y);
			gameManager->getRenderManager()->getWindow()->draw(*this->spriteHUD);

			//Name
			sf::Text text(character->getCharacterData()->getName(), *(gameManager->getFontManager()->getFont(FONT_ARIAL)));
			text.setColor(sf::Color(NAME_COLOR_RED, NAME_COLOR_GREEN, NAME_COLOR_BLUE));
			text.setScale((float)NAME_SCALE_X, (float)NAME_SCALE_Y);
			text.setPosition((float)listPositionsName[i].getX() - text.getCharacterSize(), (float)listPositionsName[i].getY());
			gameManager->getRenderManager()->getWindow()->draw(text);
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
