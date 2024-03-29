#include "Level.h"
#include "Level_Defines.h"
#include "GameManager.h"
#include "CharacterSelectionMenu.h"


Level::Level(void)
{
	this->positionDisplay = new Position();
	this->levelData = new LevelData();
	this->spriteLevel = new sf::Sprite();
	this->levelState = STATE_LEVEL_START_ROUND;
	this->timer = new Timer(false, 2);
	this->endOfLevelReached = false;
	this->listAnimation = new vector<AnimationLevel*>();
	this->listSpriteLevelAnim = new vector<sf::Sprite*>();
}

Level::Level(const LevelData * levelData)
{
	this->levelData = levelData;
	this->spriteLevel = new sf::Sprite();
	this->spriteLevel->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(this->levelData->getFileName()));
	this->positionDisplay = new Position((double)SCREEN_SIZE_WIDTH / 2 - this->spriteLevel->getTexture()->getSize().x / 2, (double)SCREEN_SIZE_HEIGHT - this->spriteLevel->getTexture()->getSize().y);
	this->levelState = STATE_LEVEL_START_ROUND;
	this->timer = new Timer(false, 2);
	this->endOfLevelReached = false;
	this->listAnimation = new vector<AnimationLevel*>();
	this->listSpriteLevelAnim = new vector<sf::Sprite*>();

	for(unsigned int i = 0; i < this->levelData->getLevelAnimationData().size(); ++i)
	{
		this->listAnimation->push_back(new AnimationLevel(this->levelData->getLevelID(),i));
		this->listSpriteLevelAnim->push_back(new sf::Sprite());
		this->listAnimation->at(i)->setPosXSprite((double)SCREEN_SIZE_WIDTH / 2 - this->spriteLevel->getTexture()->getSize().x / 2 + listAnimation->at(i)->getPosXOriginalSpritePosition());
		GameManager::getInstance()->getAnimationManager()->addLevelAnimation(this->listAnimation->at(i));
	}
}

Level::~Level(void)
{
	delete this->positionDisplay;
	delete this->spriteLevel;
	delete this->timer;
	//delete this->anim;
	for(unsigned int i = 0; i < this->levelData->getLevelAnimationData().size(); ++i)
	{
        delete this->listAnimation->at(i);
        delete this->listSpriteLevelAnim->at(i);
	}
	delete this->listAnimation;
	delete this->listSpriteLevelAnim;
}

void Level::updateLevel()
{
	switch (this->levelState)
	{
	case STATE_LEVEL_START_ROUND:
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
				this->timer->reset(true, 99);
				this->levelState = STATE_LEVEL_ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(true);
				for(unsigned int i = 0; i < listCharacters->size(); ++i)
				{
					listCharacters->at(i)->restoreHp(listCharacters->at(i)->getCharacterData()->getTotalHP());
				}
			}
		}
		break;
	case STATE_LEVEL_ROUND:
		{
			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
				this->timer->reset(true, 2);
				Character * character = GameManager::getInstance()->getCharacterManager()->getCharacterWithMaxHp();
				if (character != NULL)
				{
					character->setNumberRoundWin(character->getNumberRoundWin() + 1);
					this->nextStateLevel(character);
				}
				else
					this->levelState = STATE_LEVEL_END_ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
			}
		}
		break;
	case STATE_LEVEL_END_ROUND:
		{
			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
				this->timer->reset(true, 1);
				this->levelState = STATE_LEVEL_START_ROUND;
				GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
				vector<Character*> * listCharacters = GameManager::getInstance()->getCharacterManager()->getCharacters();
				for(unsigned int i = 0; i < listCharacters->size(); ++i)
				{
					listCharacters->at(i)->resetInformations();
				}
			}
		}
		break;
	case STATE_LEVEL_END_MATCH:
		{
			this->timer->updateTimer();
			if (this->timer->isOnLimit())
			{
			    GameManager::getInstance()->getCharacterManager()->unloadCharacters();
			    GameManager::getInstance()->getLevelManager()->unloadActiveLevel();
				GameManager::getInstance()->getAnimationManager()->cleanAnimations();
                GameManager::getInstance()->getMenuManager()->setActiveMenu(new CharacterSelectionMenu());
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

	//Draw anims
	int height;
	double posAnimX;
	double posAnimY;
	/*Collider * colliderLevel = new Collider();
	colliderLevel->setPosition(new Position(*this->positionDisplay));
	colliderLevel->setHalfSizeX(SCREEN_SIZE_WIDTH / 2);
	colliderLevel->setHalfSizeY(SCREEN_SIZE_HEIGHT / 2);
	Collider * colliderAnim = new Collider();*/

	for(unsigned int i = 0; i < this->levelData->getLevelAnimationData().size(); ++i)
	{
		height = this->listAnimation->at(i)->getAnimationData()->getSpriteHeight();
		posAnimX = this->listAnimation->at(i)->getPosXSprite();
		posAnimY = this->listAnimation->at(i)->getPosYSprite();

		/*colliderAnim->setPosition(new Position(posAnimX, posAnimY - height));
		colliderAnim->setHalfSizeX(this->listAnimation->at(i)->getAnimationData()->getSpriteWidth() / 2);
		colliderAnim->setHalfSizeY(height / 2);

		if (colliderLevel->AreColliding(colliderAnim))
		{*/
            this->listSpriteLevelAnim->at(i)->setPosition((float)posAnimX, (float)(posAnimY - height));
            this->listAnimation->at(i)->renderAnimation(this->listSpriteLevelAnim->at(i));
		//}
	}
	/*delete colliderLevel;
	delete colliderAnim;*/
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
	double moveX = this->positionDisplay->getX() - posX;

	double posXAnim;

	this->positionDisplay->setX(posX);

	if(posX >= 0)
	{
		this->positionDisplay->setX(0);
		this->endOfLevelReached = true;

		for(unsigned int i = 0; i < this->levelData->getLevelAnimationData().size(); ++i)
		{
			listAnimation->at(i)->setPosXSprite(listAnimation->at(i)->getPosXOriginalSpritePosition());
		}
	}
	else if(posX + levelWidth <= SCREEN_SIZE_WIDTH)
	{
		this->positionDisplay->setX(SCREEN_SIZE_WIDTH - levelWidth);
		this->endOfLevelReached = true;

		for(unsigned int i = 0; i < this->levelData->getLevelAnimationData().size(); ++i)
		{
			listAnimation->at(i)->setPosXSprite(SCREEN_SIZE_WIDTH - levelWidth + listAnimation->at(i)->getPosXOriginalSpritePosition());
		}
	}
	else
	{
		this->endOfLevelReached = false;

		for(unsigned int i = 0; i < this->levelData->getLevelAnimationData().size(); ++i)
		{
			posXAnim = this->listAnimation->at(i)->getPosXSprite() - moveX;
			listAnimation->at(i)->setPosXSprite(posXAnim);
		}
	}
}

LevelState Level::getLevelState()
{
	return this->levelState;
}

void Level::nextStateLevel(Character * characterWin)
{
	if (characterWin->getNumberRoundWin() >= NUMBER_ROUND_WIN_TO_FINISH_FIGHT)
		this->levelState = STATE_LEVEL_END_MATCH;
	else
		this->levelState = STATE_LEVEL_END_ROUND;
    this->timer->reset(true, 2);
	GameManager::getInstance()->getHudManager()->setDoRenderHUDTime(false);
}
