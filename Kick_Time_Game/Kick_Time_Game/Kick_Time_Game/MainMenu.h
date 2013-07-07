#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "Menu.h"

class MainMenu : public Menu
{
public:
	MainMenu(void);
	~MainMenu(void);
	void actionExit(Button * button);
	void actionGoToOption(Button * button);
	void actionNewGame(Button * button);
};

#endif
