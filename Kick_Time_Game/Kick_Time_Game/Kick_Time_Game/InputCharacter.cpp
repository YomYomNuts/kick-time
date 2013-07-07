#include "InputCharacter.h"


InputCharacter::InputCharacter()
{
    this->listInputs = new vector<sf::Keyboard::Key>();
    this->indexJoystick = -1;
}

InputCharacter::~InputCharacter()
{
    delete this->listInputs;
}

void InputCharacter::setListInputs(vector<sf::Keyboard::Key> * listInputs)
{
    this->listInputs = listInputs;
}

void InputCharacter::setIndexJoystick(int indexJoystick)
{
    this->indexJoystick = indexJoystick;
}

bool InputCharacter::isPressed(int indexAction)
{
	if (this->indexJoystick == -1 || (this->indexJoystick != -1 && sf::Joystick::isConnected(this->indexJoystick)))
		return sf::Keyboard::isKeyPressed(this->listInputs->at(indexAction));
	else
		return sf::Joystick::isButtonPressed(this->indexJoystick, indexAction);
}
