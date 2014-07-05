#include "InputMenu.h"
#include "InputMenu_Defines.h"
#include "GameManager.h"
#include "InputManager.h"
#include "InputCharacter.h"
#include "OptionMenu.h"

#include <stdio.h>

InputMenu::InputMenu()
{
	this->listButtonsInformations = new vector<Button*>();
	this->listInputsChange = new vector<bool>(NUMBER_FIGHTERS, false);

    // Add the button for the information
    for (int i = 0; i < NUMBER_INPUT_NEED + 1; ++i)
    {
        switch(i)
        {
        case 0:
            this->listButtonsInformations->push_back(new Button("JUMP/UP", new Position(POSITION_JUMP_X, POSITION_JUMP_Y), false, false, true, 0));
            break;
        case 1:
            this->listButtonsInformations->push_back(new Button("CROUCH/DOWN", new Position(POSITION_CROUCH_X, POSITION_CROUCH_Y), false, false, true, 0));
            break;
        case 2:
            this->listButtonsInformations->push_back(new Button("LEFT", new Position(POSITION_LEFT_X, POSITION_LEFT_Y), false, false, true, 0));
            break;
        case 3:
            this->listButtonsInformations->push_back(new Button("RIGHT", new Position(POSITION_RIGHT_X, POSITION_RIGHT_Y), false, false, true, 0));
            break;
        case 4:
            this->listButtonsInformations->push_back(new Button("PUNCH", new Position(POSITION_PUNCH_X, POSITION_PUNCH_Y), false, false, true, 0));
            break;
        case 5:
            this->listButtonsInformations->push_back(new Button("KICK", new Position(POSITION_KICK_X, POSITION_KICK_Y), false, false, true, 0));
            break;
        case 6:
            this->listButtonsInformations->push_back(new Button("-----", new Position(POSITION_NOTHING_X, POSITION_NOTHING_Y), false, false, true, 0));
            break;
        case 7:
            this->listButtonsInformations->push_back(new Button("GUARD", new Position(POSITION_GUARD_X, POSITION_GUARD_Y), false, false, true, 0));
            break;
        case 8:
            this->listButtonsInformations->push_back(new Button("JOYSTICK", new Position(POSITION_JOYSTICK_X, POSITION_JOYSTICK_Y), false, false, true, 0));
            break;
        }
    }

    Button * button;
    InputManager * inputManager = GameManager::getInstance()->getInputManager();
    InputCharacter * inputCharacter;
    vector<bool> * active = new vector<bool>(NUMBER_FIGHTERS, true);
    Position * position;
    char buffer[20];
    for (int i = 0; i < NUMBER_FIGHTERS; ++i)
    {
        inputCharacter = inputManager->getListInputsCharacter()->at(i);
        for (unsigned int j = 0; j < inputCharacter->getListInputs()->size() + 1; ++j)
        {
            position = new Position(*this->listButtonsInformations->at(j)->getCenter());
			position->setX(position->getX() + OFFSET_WITH_INFORMATIONS_X + i * OFFSET_BETWEEN_PLAYER_X);
            position->setY(position->getY() + OFFSET_WITH_INFORMATIONS_Y + i * OFFSET_BETWEEN_PLAYER_Y);
            if (j < inputCharacter->getListInputs()->size())
                this->listButtons->push_back(new Button(inputCharacter->getKeyName(j), position, true, active->at(i), false, i));
            else
            {
                if (inputCharacter->getIndexJoystick() != -1)
                {
#ifndef VISUAL
                    snprintf(buffer, 3, "%d", inputCharacter->getIndexJoystick() + 1);
#else
                    sprintf_s(buffer, "%d", inputCharacter->getIndexJoystick() + 1);
#endif
                    this->listButtons->push_back(new Button(buffer, position, true, active->at(i), false, i));
                }
                else
                {
                    this->listButtons->push_back(new Button("X", position, true, active->at(i), false, i));
                }
            }
            button = this->listButtons->at(this->listButtons->size() - 1);
            button->setAction(&Menu::actionChangeInputs);
            button->setActionMove(&Menu::listMove);
            active->at(i) = false;
        }
    }

    for (int i = 0; i < NUMBER_FIGHTERS; ++i)
    {
        // The name of player
#ifndef VISUAL
        snprintf(buffer, 20, "Player %d", i + 1);
#else
        sprintf_s(buffer, "Player %d", i + 1);
#endif
        position = new Position(POSITION_PLAYER_NAME_X + i * OFFSET_BETWEEN_PLAYER_NAME_X, POSITION_PLAYER_NAME_Y + i * OFFSET_BETWEEN_PLAYER_NAME_Y );
        this->listButtons->push_back(new Button(buffer, position, false, false, false, i));
    }

	this->listButtons->push_back(new Button("Back", new Position(POSITION_BACK_X, POSITION_BACK_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionBack);
	button->setActionMove(&Menu::classicMove);

	this->spriteMenu->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(FILE_MENU));
}

InputMenu::~InputMenu()
{
	for (unsigned int i = 0; i < this->listButtonsInformations->size(); ++i)
	{
        delete this->listButtonsInformations->at(i);
	}
	delete this->listButtonsInformations;
	delete this->listInputsChange;
}

void InputMenu::updateMenu()
{
    Button * button;
	for (unsigned int i = 0; i < this->listButtons->size(); ++i)
	{
	    button = this->listButtons->at(i);
		if (i < this->listButtons->size() - NUMBER_FIGHTERS - 1)
		{
			if (!this->listInputsChange->at(button->getIndexPlayer()))
				button->updateButton();
			else if (button->getIsActive())
				this->applyChangeInputs(button, i % (NUMBER_INPUT_NEED + 1));
		}
		else
		{
			button->updateButton();
		}
	}
}

void InputMenu::renderMenu()
{
	Menu::renderMenu();

    bool active;
    Button * button, * other;
    for (unsigned int i = 0; i < this->listButtonsInformations->size(); ++i)
    {
        other = this->listButtonsInformations->at(i);
        active = false;
        for (int j = i; j < (NUMBER_INPUT_NEED + 1) * NUMBER_FIGHTERS; j += NUMBER_INPUT_NEED + 1)
        {
            button = this->listButtons->at(j);
            if (button->getIsActive())
                active = true;
        }
        other->setIsActive(active);
        other->renderButton();
        other->setIsActive(false);
    }
}

void InputMenu::actionBack(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new OptionMenu());
}

void InputMenu::actionChangeInputs(Button * button)
{
    this->listInputsChange->at(button->getIndexPlayer()) = true;
}

void InputMenu::applyChangeInputs(Button * button, int indexButton)
{
	GameManager * gameManager = GameManager::getInstance();
    InputCharacter * inputCharacter = gameManager->getInputManager()->getListInputsCharacter()->at(button->getIndexPlayer());
    sf::Event * event = gameManager->getRenderManager()->getEvent();
    button->updateTimerFrameGetInput();
    if (button->getTimerFrameGetInput() > TIMER_GET_INPUT_BUTTON)
    {
        if (indexButton < NUMBER_INPUT_NEED)
        {
            if (sf::Keyboard::isKeyPressed(event->key.code))
            {
                button->resetTimerFrameGetInput();
                inputCharacter->setInput(indexButton, event->key.code);
                button->setName(inputCharacter->getKeyName(indexButton));
                this->listInputsChange->at(button->getIndexPlayer()) = false;
            }
        }
        else
        {
            int indexJoystick = inputCharacter->getIndexJoystick();
            if (gameManager->getInputManager()->isPressed(button->getIndexPlayer(), POSITION_INPUT_MOVE_UP))
            {
                button->resetTimerFrameGetInput();
                inputCharacter->setIndexJoystick(indexJoystick + 1);
                this->listInputsChange->at(button->getIndexPlayer()) = false;
            }
            else if (gameManager->getInputManager()->isPressed(button->getIndexPlayer(), POSITION_INPUT_MOVE_DOWN))
            {
                button->resetTimerFrameGetInput();
                inputCharacter->setIndexJoystick(indexJoystick - 1);
                this->listInputsChange->at(button->getIndexPlayer()) = false;
            }
            else if (gameManager->getInputManager()->isPressed(button->getIndexPlayer(), POSITION_INPUT_MOVE_LEFT))
            {
                button->resetTimerFrameGetInput();
                inputCharacter->setIndexJoystick(indexJoystick - 1);
                this->listInputsChange->at(button->getIndexPlayer()) = false;
            }
            else if (gameManager->getInputManager()->isPressed(button->getIndexPlayer(), POSITION_INPUT_MOVE_RIGHT))
            {
                button->resetTimerFrameGetInput();
                inputCharacter->setIndexJoystick(indexJoystick + 1);
                this->listInputsChange->at(button->getIndexPlayer()) = false;
            }

            if (inputCharacter->getIndexJoystick() != -1)
            {
                char buffer[3];
#ifndef VISUAL
                snprintf(buffer, 3, "%d", (inputCharacter->getIndexJoystick() + 1));
#else
                sprintf_s(buffer, "%d", (inputCharacter->getIndexJoystick() + 1));
#endif
                button->setName(buffer);
            }
            else
            {
                button->setName("X");
            }
        }
    }
}
