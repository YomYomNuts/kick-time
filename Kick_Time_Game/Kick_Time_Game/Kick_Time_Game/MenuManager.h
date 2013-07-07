#ifndef _MENUMANAGER_H
#define _MENUMANAGER_H

#include "Menu.h"

class MenuManager
{
private:
	Menu * activeMenu;
public:
	MenuManager(void);
	~MenuManager(void);
	void initializeMenuManager();
	void updateMenuManager();
	void renderMenuManager();
	Menu * getActiveMenu();
	void setActiveMenu(Menu * newMenu);
};

#endif