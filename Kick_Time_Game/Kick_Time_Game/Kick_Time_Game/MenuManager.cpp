#include "MenuManager.h"
#include "MainMenu.h"


MenuManager::MenuManager(void)
{
	this->activeMenu = NULL;
	this->previousMenu = NULL;
}

MenuManager::~MenuManager(void)
{
	if (this->activeMenu != NULL)
        delete this->activeMenu;
	if (this->previousMenu != NULL)
        delete this->previousMenu;
}

void MenuManager::initializeMenuManager()
{
	this->activeMenu = new MainMenu();
}

void MenuManager::updateMenuManager()
{
	if (this->previousMenu != NULL)
    {
        delete this->previousMenu;
        this->previousMenu = NULL;
    }
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
    this->previousMenu = this->activeMenu;
	this->activeMenu = newMenu;
}
