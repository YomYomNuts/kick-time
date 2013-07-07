#ifndef _INPUTCHARACTER_H
#define _INPUTCHARACTER_H

#include "Position.h"

#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

class InputCharacter
{
private:
    vector<sf::Keyboard::Key> * listInputs;
    int indexJoystick;
public:
    InputCharacter();
    ~InputCharacter();
    void setListInputs(vector<sf::Keyboard::Key> * listInputs);
    void setIndexJoystick(int indexJoystick);
	bool isPressed(int indexAction);
};

#endif // _INPUTCHARACTER_H
