#include "MenuManager.h"
#include "MainMenu.h"


MenuManager::MenuManager(void)
{
	this->activeMenu = NULL;
}

MenuManager::~MenuManager(void)
{
	delete this->activeMenu;
}

void MenuManager::initializeMenuManager()
{
	this->activeMenu = new MainMenu();
}

void MenuManager::updateMenuManager()
{
	if (this->activeMenu != NULL)
		this->activeMenu->updateMenu();
}

void MenuManager::renderMenuManager()
{
	if (this->activeMenu != NULL)
		this->activeMenu->renderMenu();
}

Menu * MenuManager::getActiveMenu()
{
	return this->activeMenu;
}

void MenuManager::setActiveMenu(Menu * newMenu)
{
	this->activeMenu = newMenu;
}