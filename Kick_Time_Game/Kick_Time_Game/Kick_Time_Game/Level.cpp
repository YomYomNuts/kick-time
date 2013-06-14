#include "Level.h"
#include "Level_Defines.h"
#include "GameManager.h"

#include <iostream>

Level::Level(void)
{
	this->positionDisplay = new Position();
	this->levelData = new LevelData();
	this->spriteLevel = new sf::Sprite();
	this->levelState = LevelState::START_ROUND;
	this->timer = new Timer(false, 2);
	this->endOfLevelReached = false;
}

Level::Level(const LevelData * levelData)
{
	this->levelData = levelData;
	this->spriteLevel = new sf::Sprite();
	this->spriteLevel->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->levelData->getFileName()));
	this->positionDisplay = new Position((double)SCREEN_SIZE_WIDTH / 2 - this->spriteLevel->getTexture()->getSize().x / 2, (double)SCREEN_SIZE_HEIGHT - this->spriteLevel->getTexture()->getSize().y);
	this->levelState = LevelState::START_ROUND;
	this->timer = new Timer(false, 2);
	this->endOfLevelReached = false;
}

Level::~Level(void)
{
	delete this->positionDisplay;
	delete this->spriteLevel;
	delete this->timer;
}

void Level::updateLevel()
{
	switch (this->levelState)
	{
	case LevelState::START_ROUND:
		{
			// Restore the life
			vector<Character*> * listCharacters = GameManager::getInstance()->getCharacterManager()->getCharacters();
			for(unsigned int i = 0; i < listCharacters->size(); ++i)
			{
				listCharacters->at(i)->restoreHp(listCharacters->at(i)->getCharacterData()->getTotalHP() * this->timer->getCurrentFrame() / this->timer->getNumberTotalFrame());
			}

			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
				this->timer = new Timer(true, 99);
				this->levelState = LevelState::ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(true);
				for(unsigned int i = 0; i < listCharacters->size(); ++i)
				{
					listCharacters->at(i)->restoreHp(listCharacters->at(i)->getCharacterData()->getTotalHP());
				}
			}
		}
		break;
	case LevelState::ROUND:
		{
			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
				this->timer = new Timer(true, 2);
				Character * character = GameManager::getInstance()->getCharacterManager()->getCharacterWithMaxHp();
				if (character != NULL)
				{
					character->setNumberRoundWin(character->getNumberRoundWin() + 1);
					this->nextStateLevel(character);
				}
				else
					this->levelState = LevelState::END_ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
			}
		}
		break;
	case LevelState::END_ROUND:
		{
			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
				this->timer = new Timer(true, 1);
				this->levelState = LevelState::START_ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
				vector<Character*> * listCharacters = GameManager::getInstance()->getCharacterManager()->getCharacters();
				for(unsigned int i = 0; i < listCharacters->size(); ++i)
				{
					listCharacters->at(i)->resetInformations();
				}
			}
		}
		break;
	case LevelState::END_MATCH:
		{
			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
				this->timer = new Timer(true, 1);
				this->levelState = LevelState::START_ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
				vector<Character*> * listCharacters = GameManager::getInstance()->getCharacterManager()->getCharacters();
				for(unsigned int i = 0; i < listCharacters->size(); ++i)
				{
					listCharacters->at(i)->resetInformations();
					listCharacters->at(i)->setNumberRoundWin(0);
				}
			}
		}
		break;
	}
}

void Level::renderLevel()
{
	//Draw
	this->spriteLevel->setPosition((float)this->positionDisplay->getX(), (float)this->positionDisplay->getY());
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteLevel);
}

int Level::getTimer()
{
	if (this->timer != NULL)
		return this->timer->getTime();
	return 0;
}

const LevelData * Level::getLevelData()
{
	return this->levelData;
}

Position * Level::getPosition()
{
	return positionDisplay;
}

void Level::setEndOfLevelReachedState(bool endOfScreen)
{
	this->endOfLevelReached = endOfScreen;
}

bool Level::getEndOfLevelReachedState()
{
	return this->endOfLevelReached;
}

sf::Sprite * Level::getSpriteLevel()
{
	return this->spriteLevel;
}

void Level::setPosX(double posX)
{
	double levelWidth = this->spriteLevel->getTexture()->getSize().x;
	double posXlevel = this->positionDisplay->getX();

	this->positionDisplay->setX(posX);

	if(posX >= 0)
	{
		this->positionDisplay->setX(0);
		this->endOfLevelReached = true;
	}
	else if(posX + levelWidth <= SCREEN_SIZE_WIDTH)
	{
		this->positionDisplay->setX(SCREEN_SIZE_WIDTH- levelWidth);
		this->endOfLevelReached = true;
	}
	else
		this->endOfLevelReached = false;
}

LevelState Level::getLevelState()
{
	return this->levelState;
}

void Level::nextStateLevel(Character * characterWin)
{
	if (characterWin->getNumberRoundWin() >= NUMBER_ROUND_WIN_TO_FINISH_FIGHT)
		this->levelState = LevelState::END_MATCH;
	else
		this->levelState = LevelState::END_ROUND;
	this->timer = new Timer(true, 2);
	GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
}