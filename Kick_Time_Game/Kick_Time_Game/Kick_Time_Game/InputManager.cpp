#include "InputManager.h"

InputManager::InputManager(void)
{
}

InputManager::~InputManager(void)
{
}

void InputManager::initializeInputManager()
{
	//Input Player 1
	this->listInputs[0][POSITION_INPUT_MOVE_UP] = sf::Keyboard::Z;
	this->listInputs[0][POSITION_INPUT_MOVE_DOWN] = sf::Keyboard::S;
	this->listInputs[0][POSITION_INPUT_MOVE_LEFT] = sf::Keyboard::Q;
	this->listInputs[0][POSITION_INPUT_MOVE_RIGHT] = sf::Keyboard::D;
	this->listInputs[0][POSITION_INPUT_ACTION_1] = sf::Keyboard::I;
	this->listInputs[0][POSITION_INPUT_ACTION_2] = sf::Keyboard::J;
	this->listInputs[0][POSITION_INPUT_ACTION_3] = sf::Keyboard::K;
	this->listInputs[0][POSITION_INPUT_ACTION_4] = sf::Keyboard::L;
	
	//Input Player 2
	this->listInputs[1][POSITION_INPUT_MOVE_UP] = sf::Keyboard::Up;
	this->listInputs[1][POSITION_INPUT_MOVE_DOWN] = sf::Keyboard::Down;
	this->listInputs[1][POSITION_INPUT_MOVE_LEFT] = sf::Keyboard::Left;
	this->listInputs[1][POSITION_INPUT_MOVE_RIGHT] = sf::Keyboard::Right;
	this->listInputs[1][POSITION_INPUT_ACTION_1] = sf::Keyboard::Num5;
	this->listInputs[1][POSITION_INPUT_ACTION_2] = sf::Keyboard::Num1;
	this->listInputs[1][POSITION_INPUT_ACTION_3] = sf::Keyboard::Num2;
	this->listInputs[1][POSITION_INPUT_ACTION_4] = sf::Keyboard::Num3;
}

void InputManager::updateInputManager()
{
}

Position InputManager::getPositionMovement(int indexPlayer, int indexJoystick)
{
	Position position;

	if (indexJoystick == -1 || (indexJoystick != -1 && sf::Joystick::isConnected(indexJoystick)))
	{
		//Use keyboard
		if (sf::Keyboard::isKeyPressed(this->listInputs[indexPlayer][POSITION_INPUT_MOVE_UP]))
			position.setY(1);
		if (sf::Keyboard::isKeyPressed(this->listInputs[indexPlayer][POSITION_INPUT_MOVE_DOWN]))
			position.setY(position.getY() - 1);
		if (sf::Keyboard::isKeyPressed(this->listInputs[indexPlayer][POSITION_INPUT_MOVE_LEFT]))
			position.setX(-1);
		if (sf::Keyboard::isKeyPressed(this->listInputs[indexPlayer][POSITION_INPUT_MOVE_RIGHT]))
			position.setX(position.getX() + 1);
	}
	else
	{
		position.setY((int)sf::Joystick::getAxisPosition(indexJoystick, sf::Joystick::Y));
		position.setX((int)sf::Joystick::getAxisPosition(indexJoystick, sf::Joystick::X));
	}

	return position;
}

bool InputManager::isPressed(int indexPlayer, int indexAction, int indexJoystick)
{
	if (indexJoystick == -1 || (indexJoystick != -1 && sf::Joystick::isConnected(indexJoystick)))
		return sf::Keyboard::isKeyPressed(this->listInputs[indexPlayer][indexAction]);
	else
		return sf::Joystick::isButtonPressed(indexJoystick, indexAction);
}