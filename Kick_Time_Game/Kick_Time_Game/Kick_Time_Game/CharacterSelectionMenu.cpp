#include "CharacterSelectionMenu.h"
#include "CharacterSelectionMenu_Defines.h"
#include "CharacterData.h"
#include "GameManager.h"
#include "MainMenu.h"


CharacterSelectionMenu::CharacterSelectionMenu() : Menu()
{
    this->listAvatars = new vector<sf::Sprite*>();
    this->numberPlayerValidate = 0;

    Button * button;
    int indexLine = 0, indexColumn = 0;
    bool active = true;
    sf::Sprite * sprite;
    TextureManager * textureManager = GameManager::getInstance()->getTextureManager();
    Position * position;
	for (int i = 0; i < NUMBER_CHARACTERDATA; ++i)
    {
        indexColumn = i % NUMBER_CHARACTER_BY_LINE;
        indexLine = (int)(i / NUMBER_CHARACTER_BY_LINE);
        position = new Position(POSITION_FIRST_CHARACTER_X + indexColumn * OFFSET_CHARACTER_X, POSITION_FIRST_CHARACTER_Y + indexLine * OFFSET_CHARACTER_Y);
        for (int j = 0; j < NUMBER_FIGHTERS; ++j)
        {
            this->listButtons->push_back(new Button("", position, true, active, false, j));
            button = this->listButtons->at(this->listButtons->size() - 1);
            button->setAction(&Menu::actionValidateCharacter);
            button->setActionMove(&Menu::characterMove);
        }

        this->listAvatars->push_back(new sf::Sprite());
        sprite = this->listAvatars->at(this->listAvatars->size() - 1);
        sprite->setTexture(*textureManager->getTexture(characterDataArray[i].getPathAvatar()));
        sprite->setPosition((float)(position->getX() - sprite->getTextureRect().width / 2), (float)(position->getY() - sprite->getTextureRect().height / 2));

        active = false;
    }

    // Button back
	this->listButtons->push_back(new Button("Back", new Position(POSITION_BACK_X, POSITION_BACK_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionBack);
	button->setActionMove(&Menu::classicMove);
}

CharacterSelectionMenu::~CharacterSelectionMenu()
{
	delete this->spriteMenu;
	delete this->listButtons;
    delete this->listAvatars;
}

void CharacterSelectionMenu::renderMenu()
{
	Menu::renderMenu();

    // Render avatar
    for (unsigned int i = 0; i < this->listAvatars->size(); ++i)
    {
		GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->listAvatars->at(i));
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
            rectangle->setSize(sf::Vector2f((float)(this->listAvatars->at(i / NUMBER_FIGHTERS)->getTextureRect().width), (float)(this->listAvatars->at(i / NUMBER_FIGHTERS)->getTextureRect().height)));
            rectangle->setPosition((float)button->getCenter()->getX() - rectangle->getSize().x / 2, (float)button->getCenter()->getY() - rectangle->getSize().y / 2);
            GameManager::getInstance()->getRenderManager()->getWindow()->draw(*rectangle);
        }
    }
}

void CharacterSelectionMenu::actionBack(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new MainMenu());
}

void CharacterSelectionMenu::actionValidateCharacter(Button * button)
{
    //Inactive all the buttons of this player
	Button * buttonTemp;
	int indexButton = 0;
    for (unsigned int i = 0; i < this->listButtons->size(); ++i)
    {
        buttonTemp = this->listButtons->at(i);
        if (buttonTemp->getIndexPlayer() == button->getIndexPlayer())
        {
            buttonTemp->setCanBeActive(false);
            if (buttonTemp == button)
                indexButton = i;
        }
    }
    //GameManager::getInstance()->getCharacterManager()->addCharacter((int)(indexButton / NUMBER_FIGHTERS));

    ++this->numberPlayerValidate;
    //if (this->numberPlayerValidate == NUMBER_FIGHTERS)
    //    GameManager::getInstance()->getMenuManager()->setActiveMenu(new LevelSelectionMenu());
}

void CharacterSelectionMenu::characterMove(Button * button, ButtonDirection direction)
{
	switch (direction)
	{
	case BUTTON_DIRECTION_UP:
	case BUTTON_DIRECTION_DOWN:
		{
			Button * nextButton = Menu::getNextButton(button, direction, false);
			if (nextButton != NULL)
			{
				button->setIsActive(false);
				nextButton->setIsActive(true);
			}
		}
		break;
	case BUTTON_DIRECTION_LEFT:
	    {
			Button * nextButton = Menu::getNextButton(button, direction, true);
			if (nextButton != NULL)
			{
				button->setIsActive(false);
				nextButton->setIsActive(true);
			}
			else
            {
                Button * tempButton = button;
				nextButton = button;
                while (tempButton != NULL)
                {
                    tempButton = Menu::getNextButton(nextButton, BUTTON_DIRECTION_RIGHT, true);
                    if (tempButton != NULL)
                        nextButton = tempButton;
                }
				button->setIsActive(false);
				nextButton->setIsActive(true);
            }
	    }
        break;
	case BUTTON_DIRECTION_RIGHT:
	    {
			Button * nextButton = Menu::getNextButton(button, direction, true);
			if (nextButton != NULL)
			{
				button->setIsActive(false);
				nextButton->setIsActive(true);
			}
			else
            {
                Button * tempButton = button;
				nextButton = button;
                while (tempButton != NULL)
                {
                    tempButton = Menu::getNextButton(nextButton, BUTTON_DIRECTION_LEFT, true);
                    if (tempButton != NULL)
                        nextButton = tempButton;
                }
				button->setIsActive(false);
				nextButton->setIsActive(true);
            }
	    }
		break;
	}
}
