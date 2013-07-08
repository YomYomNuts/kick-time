#ifndef _BUTTON_H
#define _BUTTON_H


// Direction move Button
enum ButtonDirection {
	BUTTON_DIRECTION_UP,
	BUTTON_DIRECTION_DOWN,
	BUTTON_DIRECTION_LEFT,
	BUTTON_DIRECTION_RIGHT
};

#include "Button_Defines.h"
#include "Position.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>

#include <string>

using namespace std;

class Menu;

class Button
{
private:
	string name;
	Position * center;
	bool canBeActive;
	bool isActive;
	bool display;
	void (Menu::*action)(Button*);
	void (Menu::*actionMove)(Button*, ButtonDirection);
	int timerFrameGetInput;
	int indexPlayer;
	sf::Text * textRender;
public:
	Button(void);
    Button(string name, Position * center, bool canBeActive, bool isActive, bool display, int indexPlayer);
	~Button(void);
	void updateButton();
	void renderButton();
	bool getIsActive();
	void setIsActive(bool isActive);
	bool getCanBeActive();
	void setCanBeActive(bool canBeActive);
	Position * getCenter();
	void setAction(void (Menu::*action)(Button*));
	void setActionMove(void (Menu::*actionMove)(Button*, ButtonDirection));
	int getIndexPlayer();
	void setName(string name);
	int getTimerFrameGetInput();
	void updateTimerFrameGetInput();
	void resetTimerFrameGetInput();
};

#endif
