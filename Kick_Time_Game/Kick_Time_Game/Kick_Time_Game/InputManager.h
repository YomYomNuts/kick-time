#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include "GameManager_Defines.h"
#include "InputManager_Defines.h"
#include "Position.h"

#include <SFML/Graphics.hpp>

class InputManager
{
private:
	sf::Keyboard::Key listInputs[NUMBER_FIGHTERS][NUMBER_INPUTS];

public:
	InputManager(void);
	~InputManager(void);
	void initializeInputManager();
	void updateInputManager();
	Position getPositionMovement(int indexPlayer, int indexJoystick);
	bool isPressed(int indexPlayer, int indexAction, int indexJoystick);
};

#endif