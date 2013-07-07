#ifndef _MENU_H
#define _MENU_H

#include "Button.h"
#include "Button_Defines.h"

#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

class Button;

class Menu
{
protected:
	sf::Sprite * spriteMenu;
	vector<Button*> * listButtons;
	Button * getNextButton(Button * buttonCurrent, ButtonDirection direction, bool sameOtherPosition);
public:
	Menu(void);
	~Menu(void);
	virtual void updateMenu();
	virtual void renderMenu();
	void classicMove(Button * button, ButtonDirection direction);
	virtual void actionBack(Button * button) {};
	virtual void actionExit(Button * button) {};
	virtual void actionGoToOption(Button * button) {};
	virtual void actionNewGame(Button * button) {};
	virtual void actionChangeVolumeSound(Button * button) {};
	virtual void actionChangeVolumeMusic(Button * button) {};
    virtual void volumeSoundMove(Button * button, ButtonDirection direction) {};
    virtual void volumeMusicMove(Button * button, ButtonDirection direction) {};
	virtual void actionValidateCharacter(Button * button) {};
    virtual void characterMove(Button * button, ButtonDirection direction) {};
};

#endif