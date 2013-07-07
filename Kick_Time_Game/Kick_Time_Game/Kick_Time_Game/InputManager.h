#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include "InputCharacter.h"
#include "GameManager_Defines.h"
#include "InputManager_Defines.h"
#include "Position.h"

#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

class InputManager
{
private:
	vector<InputCharacter*> * listInputCharacter;

public:
	InputManager(void);
	~InputManager(void);
	void initializeInputManager();
	void updateInputManager();
	bool isPressed(int indexPlayer, int indexAction);
};

#endif
