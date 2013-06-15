#include "HudManager.h"
#include "HudManager_Defines.h"
#include "GameManager.h"
#include "FontData.h"
#include "Level_Defines.h"


const Position listPositionsLifeBar[NUMBER_FIGHTERS] = {
	Position(LIFE_BAR_POSITION_P1_X, LIFE_BAR_POSITION_P1_Y),
	Position(LIFE_BAR_POSITION_P2_X, LIFE_BAR_POSITION_P2_Y)
};

const Position listPositionsName[NUMBER_FIGHTERS] = {
	Position(NAME_POSITION_P1_X, NAME_POSITION_P1_Y),
	Position(NAME_POSITION_P2_X, NAME_POSITION_P2_Y)
};

const Position listPositionsRoundWin[NUMBER_FIGHTERS*NUMBER_ROUND_WIN_TO_FINISH_FIGHT] = {
	Position(ROUNDWIN1_POSITION_P1_X, ROUNDWIN1_POSITION_P1_Y),
	Position(ROUNDWIN2_POSITION_P1_X, ROUNDWIN2_POSITION_P1_Y),
	Position(ROUNDWIN1_POSITION_P2_X, ROUNDWIN1_POSITION_P2_Y),
	Position(ROUNDWIN2_POSITION_P2_X, ROUNDWIN2_POSITION_P2_Y)
};

HudManager::HudManager(void)
{
	this->doRenderHUDTime = false;
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
	if (this->doRenderHUDTime)
		this->renderHUDTime();
	this->renderHUDLevel();
	this->renderHUDCharacter();
}

void HudManager::renderHUDTime()
{
	Level * level = GameManager::getInstance()->getLevelManager()->getActiveLevel();
	if (level != NULL)
	{
		int timer = level->getTimer();
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

void HudManager::renderHUDCharacter()
{
	GameManager * gameManager = GameManager::getInstance();
	vector<Character*> * listCharacters = gameManager->getCharacterManager()->getCharacters();
	Character * character;
	int percent;

	for(unsigned int i = 0; i < listCharacters->size(); ++i)
	{
		character = listCharacters->at(i);
		percent = (int)((LIFE_WIDTH * character->getHp()) / character->getTotalHp());

		// Round win
		for (int j = 0; j < character->getNumberRoundWin(); ++j)
		{
			this->spriteHUD->setTextureRect(sf::IntRect(ICON_ROUND_WIN_X, ICON_ROUND_WIN_Y, ICON_ROUND_WIN_WIDTH, ICON_ROUND_WIN_HEIGHT));
			this->spriteHUD->setPosition((float)listPositionsRoundWin[i * NUMBER_FIGHTERS + j].getX(), (float)listPositionsRoundWin[i * NUMBER_FIGHTERS + j].getY());
			gameManager->getRenderManager()->getWindow()->draw(*this->spriteHUD);
		}

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
			sf::Text text(character->getCharacterData()->getName(), *(gameManager->getFontManager()->getFont(NAME_FONT)));
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
			sf::Text text(character->getCharacterData()->getName(), *(gameManager->getFontManager()->getFont(NAME_FONT)));
			text.setColor(sf::Color(NAME_COLOR_RED, NAME_COLOR_GREEN, NAME_COLOR_BLUE));
			text.setScale((float)NAME_SCALE_X, (float)NAME_SCALE_Y);
			sf::Vector2f pos = text.findCharacterPos(character->getCharacterData()->getName().length()-1);
			text.setPosition((float)listPositionsName[i].getX() - (pos.x + text.getCharacterSize()), (float)listPositionsName[i].getY());
			gameManager->getRenderManager()->getWindow()->draw(text);
		}
	}
}

void HudManager::renderHUDLevel()
{
	GameManager * gameManager = GameManager::getInstance();
	Level * level = gameManager->getLevelManager()->getActiveLevel();
	if (level != NULL)
	{
		switch (level->getLevelState())
		{
		case LevelState::START_ROUND:
			{
				this->spriteHUD->setTextureRect(sf::IntRect(TEXT_FIGHT_X, TEXT_FIGHT_Y, TEXT_FIGHT_WIDTH, TEXT_FIGHT_HEIGHT));
				this->spriteHUD->setPosition(FIGHT_POSITION_X, FIGHT_POSITION_Y);
				gameManager->getRenderManager()->getWindow()->draw(*this->spriteHUD);
			}
			break;
		case LevelState::END_ROUND:
			{
				Character * character = GameManager::getInstance()->getCharacterManager()->getCharacterWithMaxHp();
				if (character != NULL)
				{
					string winner = character->getCharacterData()->getName() + " WINNER";
					sf::Text text(winner, *(gameManager->getFontManager()->getFont(NAME_FONT)));
					text.setColor(sf::Color(WINNER_COLOR_RED, WINNER_COLOR_GREEN, WINNER_COLOR_BLUE));
					text.setScale((float)WINNER_SCALE_X, (float)WINNER_SCALE_Y);
					sf::Vector2f pos = text.findCharacterPos(winner.length()-1);
					text.setPosition(WINNER_POSITION_X - (pos.x + text.getCharacterSize()) / 2, WINNER_POSITION_Y);
					gameManager->getRenderManager()->getWindow()->draw(text);
				}
			}
			break;
		case LevelState::END_MATCH:
			{
				this->spriteHUD->setTextureRect(sf::IntRect(TEXT_FINISH_HIM_X, TEXT_FINISH_HIM_Y, TEXT_FINISH_HIM_WIDTH, TEXT_FINISH_HIM_HEIGHT));
				this->spriteHUD->setPosition(FINISH_HIM_POSITION_X, FINISH_HIM_POSITION_Y);
				gameManager->getRenderManager()->getWindow()->draw(*this->spriteHUD);
			}
			break;
		}
	}
}

void HudManager::setDoRenderHUDTime(bool active)
{
	this->doRenderHUDTime = active;
}