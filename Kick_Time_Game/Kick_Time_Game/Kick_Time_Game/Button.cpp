#include "Button.h"
#include "GameManager.h"


Button::Button(void)
{
	this->name = "";
	this->center = new Position();
	this->canBeActive = true;
	this->isActive = false;
	this->display = false;
	this->action = NULL;
	this->actionMove = NULL;
	this->indexPlayer = 0;
	this->timerFrameGetInput = 0;
	this->textRender = new sf::Text(this->name, *(GameManager::getInstance()->getFontManager()->getFont(BUTTON_FONT)));
}

Button::Button(string name, Position * center, bool canBeActive, bool isActive, bool display, int indexPlayer)
{
	this->name = name;
	this->center = center;
	this->canBeActive = canBeActive;
	this->isActive = isActive;
	this->display = display;
	this->action = NULL;
	this->actionMove = NULL;
	this->timerFrameGetInput = 0;
	this->indexPlayer = indexPlayer;
	this->textRender = new sf::Text(this->name, *(GameManager::getInstance()->getFontManager()->getFont(BUTTON_FONT)));
}

Button::~Button(void)
{
	delete this->center;
	delete this->textRender;
}

void Button::updateButton()
{
	GameManager * gameManager = GameManager::getInstance();
	Menu * activeMenu = gameManager->getMenuManager()->getActiveMenu();

	if (this->isActive)
	{
		++this->timerFrameGetInput;
		if (activeMenu != NULL && this->timerFrameGetInput >= TIMER_GET_INPUT_BUTTON)
		{
			if (this->action != NULL && gameManager->getInputManager()->isPressed(this->indexPlayer, POSITION_INPUT_ACTION_1))
			{
                // Action validate
				this->timerFrameGetInput = 0;
				(activeMenu->*action)(this);
			}
			else if (this->actionMove != NULL)
			{
                // Action move
				if (gameManager->getInputManager()->isPressed(this->indexPlayer, POSITION_INPUT_MOVE_UP))
				{
					this->timerFrameGetInput = 0;
					(activeMenu->*actionMove)(this, BUTTON_DIRECTION_UP);
				}
				else if (gameManager->getInputManager()->isPressed(this->indexPlayer, POSITION_INPUT_MOVE_DOWN))
				{
					this->timerFrameGetInput = 0;
					(activeMenu->*actionMove)(this, BUTTON_DIRECTION_DOWN);
				}
				else if (gameManager->getInputManager()->isPressed(this->indexPlayer, POSITION_INPUT_MOVE_LEFT))
				{
					this->timerFrameGetInput = 0;
					(activeMenu->*actionMove)(this, BUTTON_DIRECTION_LEFT);
				}
				else if (gameManager->getInputManager()->isPressed(this->indexPlayer, POSITION_INPUT_MOVE_RIGHT))
				{
					this->timerFrameGetInput = 0;
					(activeMenu->*actionMove)(this, BUTTON_DIRECTION_RIGHT);
				}
			}
		}
	}
}

void Button::renderButton()
{
	//Name
	if (this->isActive)
		this->textRender->setColor(sf::Color(BUTTON_ACTIVE_COLOR_RED, BUTTON_ACTIVE_COLOR_GREEN, BUTTON_ACTIVE_COLOR_BLUE));
	else
		this->textRender->setColor(sf::Color(BUTTON_COLOR_RED, BUTTON_COLOR_GREEN, BUTTON_COLOR_BLUE));

	this->textRender->setScale((float)BUTTON_SCALE_X, (float)BUTTON_SCALE_Y);
	this->textRender->setPosition((float)(this->center->getX()), (float)(this->center->getY()));
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->textRender);
}

bool Button::getIsActive()
{
	return this->isActive;
}

void Button::setIsActive(bool isActive)
{
	this->isActive = isActive;
}

bool Button::getCanBeActive()
{
	return this->canBeActive;
}

void  Button::setCanBeActive(bool canBeActive)
{
	this->canBeActive = canBeActive;
}

Position * Button::getCenter()
{
	return this->center;
}

void Button::setAction(void (Menu::*action)(Button*))
{
	this->action = action;
}

void Button::setActionMove(void (Menu::*actionMove)(Button*, ButtonDirection))
{
	this->actionMove = actionMove;
}

int Button::getIndexPlayer()
{
    return this->indexPlayer;
}

void Button::setName(string name)
{
    this->name = name;
    this->textRender->setString(this->name);
}

int Button::getTimerFrameGetInput()
{
    return this->timerFrameGetInput;
}

void Button::updateTimerFrameGetInput()
{
    ++this->timerFrameGetInput;
}

void Button::resetTimerFrameGetInput()
{
    this->timerFrameGetInput = 0;
}
