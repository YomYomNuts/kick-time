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
	vector<sf::Keyboard::Key>* getListInputs();
    void setIndexJoystick(int indexJoystick);
	int getIndexJoystick();
	bool isPressed(int indexAction);
	void setInput(int indexAction, sf::Keyboard::Key key);
    string getKeyName(int indexAction);
};

#endif  _INPUTCHARACTER_H
