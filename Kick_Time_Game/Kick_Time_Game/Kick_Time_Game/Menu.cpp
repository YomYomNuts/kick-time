#include "Menu.h"
#include "GameManager.h"

#include <climits>

Menu::Menu(void)
{
	this->spriteMenu = new sf::Sprite();
	this->title = new sf::Text();
	this->listButtons = new vector<Button*>();
}

Menu::~Menu(void)
{
	delete this->spriteMenu;
	delete this->title;
	for (unsigned int i = 0; i < this->listButtons->size(); ++i)
	{
        delete this->listButtons->at(i);
	}
	delete this->listButtons;
}

void Menu::updateMenu()
{
	for (unsigned int i = 0; i < this->listButtons->size(); ++i)
	{
		this->listButtons->at(i)->updateButton();
	}
}

void Menu::renderMenu()
{
	//Draw the background
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->spriteMenu);

	//Draw the title
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->title);

	//Draw the buttons
	for(unsigned int i = 0; i < this->listButtons->size(); ++i)
	{
		this->listButtons->at(i)->renderButton();
	}
}

Button * Menu::getNextButton(Button * buttonCurrent, ButtonDirection direction, bool sameOtherPosition)
{
	double distance = (double)INT_MAX, tempDistance = (double)INT_MAX;
	Button * buttomMove = NULL, * buttonTemp;
	bool sameX, sameY;
	for (unsigned int i = 0; i < this->listButtons->size(); ++i)
	{
		buttonTemp = this->listButtons->at(i);
		if (buttonTemp != buttonCurrent && buttonTemp->getCanBeActive() && buttonTemp->getIndexPlayer() == buttonCurrent->getIndexPlayer())
		{
			sameX = buttonTemp->getCenter()->getX() == buttonCurrent->getCenter()->getX();
			sameY = buttonTemp->getCenter()->getY() == buttonCurrent->getCenter()->getY();
			if (direction == BUTTON_DIRECTION_DOWN && ((sameOtherPosition && sameX) || !sameOtherPosition))
				tempDistance = buttonTemp->getCenter()->getY() - buttonCurrent->getCenter()->getY();
			else if(direction == BUTTON_DIRECTION_UP && ((sameOtherPosition && sameX) || !sameOtherPosition))
				tempDistance = buttonCurrent->getCenter()->getY() - buttonTemp->getCenter()->getY();
			else if(direction == BUTTON_DIRECTION_LEFT && ((sameOtherPosition && sameY) || !sameOtherPosition))
				tempDistance = buttonCurrent->getCenter()->getX() - buttonTemp->getCenter()->getX();
			else if(direction == BUTTON_DIRECTION_RIGHT && ((sameOtherPosition && sameY) || !sameOtherPosition))
				tempDistance = buttonTemp->getCenter()->getX() - buttonCurrent->getCenter()->getX();

			if (distance > tempDistance && tempDistance > 0)
			{
				distance = tempDistance;
				buttomMove = buttonTemp;
			}
		}
	}
	return buttomMove;
}

void Menu::classicMove(Button * button, ButtonDirection direction)
{
	switch (direction)
	{
	case BUTTON_DIRECTION_UP:
	case BUTTON_DIRECTION_DOWN:
		{
			Button * nextButton = this->getNextButton(button, direction, false);
			if (nextButton != NULL)
			{
				button->setIsActive(false);
				nextButton->setIsActive(true);
			}
		}
		break;
	case BUTTON_DIRECTION_LEFT:
		break;
	case BUTTON_DIRECTION_RIGHT:
		break;
	}
}

void Menu::listMove(Button * button, ButtonDirection direction)
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
