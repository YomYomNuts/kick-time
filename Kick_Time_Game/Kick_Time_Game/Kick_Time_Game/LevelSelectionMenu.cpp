#include "LevelSelectionMenu.h"
#include "LevelSelectionMenu_Defines.h"
#include "LevelData.h"
#include "GameManager.h"
#include "CharacterSelectionMenu.h"


LevelSelectionMenu::LevelSelectionMenu()
{
    this->listLevelsSprites = new vector<sf::Sprite*>();

    Button * button;
    int indexLine = 0, indexColumn = 0;
    bool active = true;
    sf::Sprite * sprite;
    TextureManager * textureManager = GameManager::getInstance()->getTextureManager();
    Position * position;
	for (int i = 0; i < NUMBER_LEVELDATA; ++i)
    {
        indexColumn = i % NUMBER_LEVEL_BY_LINE;
        indexLine = (int)(i / NUMBER_LEVEL_BY_LINE);
        position = new Position(POSITION_FIRST_LEVEL_X + indexColumn * OFFSET_LEVEL_X, POSITION_FIRST_LEVEL_Y + indexLine * OFFSET_LEVEL_Y);

        this->listButtons->push_back(new Button("", position, true, active, false, 0));
        button = this->listButtons->at(this->listButtons->size() - 1);
        button->setAction(&Menu::actionValidateLevel);
        button->setActionMove(&Menu::listMove);

        this->listLevelsSprites->push_back(new sf::Sprite());
        sprite = this->listLevelsSprites->at(this->listLevelsSprites->size() - 1);
        sprite->setTexture(*textureManager->getTexture(levelDataArray[i].getFileName()));
        sprite->setTextureRect(sf::IntRect(0, sprite->getTextureRect().height - SCREEN_SIZE_HEIGHT, sprite->getTextureRect().width, SCREEN_SIZE_HEIGHT));
        sprite->setScale((float)(SIZE_SPRITE_LEVEL_X) / sprite->getTextureRect().width, (float)(SIZE_SPRITE_LEVEL_Y) / sprite->getTextureRect().height);
        sprite->setPosition((float)(position->getX() - (sprite->getTextureRect().width / 2) * sprite->getScale().x), (float)(position->getY() - (sprite->getTextureRect().height / 2) * sprite->getScale().y));

        active = false;
    }

    // Button back
	this->listButtons->push_back(new Button("Back", new Position(POSITION_BACK_X, POSITION_BACK_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionBack);
	button->setActionMove(&Menu::classicMove);

	this->title->setString("SELECT THE ARENA");
	this->title->setFont(*(GameManager::getInstance()->getFontManager()->getFont(TITLE_LEVEL_FONT)));
	this->title->setScale((float)TITLE_LEVEL_SCALE_X, (float)TITLE_LEVEL_SCALE_Y);
	this->title->setPosition((float)(POSITION_TITLE_LEVEL_X), (float)(POSITION_TITLE_LEVEL_Y));
    this->title->setColor(sf::Color(TITLE_LEVEL_COLOR_RED, TITLE_LEVEL_COLOR_GREEN, TITLE_LEVEL_COLOR_BLUE));

	this->spriteMenu->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(FILE_MENU_SELECTION));
}

LevelSelectionMenu::~LevelSelectionMenu()
{
	for (unsigned int i = 0; i < this->listLevelsSprites->size(); ++i)
	{
        delete this->listLevelsSprites->at(i);
	}
	delete this->listLevelsSprites;
}

void LevelSelectionMenu::renderMenu()
{
	Menu::renderMenu();

    // Render level
    for (unsigned int i = 0; i < this->listLevelsSprites->size(); ++i)
    {
		GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->listLevelsSprites->at(i));
    }

    // Render selection
    Button * button;
    sf::RectangleShape * rectangle;
	int max = (int)this->listButtons->size();
    for (int i = 0; i < max - 1; ++i)
    {
        button = this->listButtons->at(i);
        if (button->getIsActive())
        {
            rectangle = new sf::RectangleShape();
            rectangle->setFillColor(sf::Color::Transparent);
            rectangle->setOutlineColor(sf::Color::Green);
            rectangle->setOutlineThickness(2);
            rectangle->setSize(sf::Vector2f((float)(this->listLevelsSprites->at(i)->getTextureRect().width * this->listLevelsSprites->at(i)->getScale().x), (float)(this->listLevelsSprites->at(i)->getTextureRect().height * this->listLevelsSprites->at(i)->getScale().y)));
            rectangle->setPosition((float)button->getCenter()->getX() - rectangle->getSize().x / 2, (float)button->getCenter()->getY() - rectangle->getSize().y / 2);
            GameManager::getInstance()->getRenderManager()->getWindow()->draw(*rectangle);
        }
    }
}

void LevelSelectionMenu::actionBack(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new CharacterSelectionMenu());
}

void LevelSelectionMenu::actionValidateLevel(Button * button)
{
	int indexButton = 0;
    for (unsigned int i = 0; i < this->listButtons->size(); ++i)
    {
        if (this->listButtons->at(i) == button)
        {
            indexButton = i;
        }
    }

    GameManager::getInstance()->getLevelManager()->setActiveLevel(indexButton);
    GameManager::getInstance()->getCharacterManager()->loadCharacters();
    GameManager::getInstance()->getMenuManager()->setActiveMenu(NULL);
}
