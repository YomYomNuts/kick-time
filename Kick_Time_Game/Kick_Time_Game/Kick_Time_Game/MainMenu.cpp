#include "MainMenu.h"
#include "MainMenu_Defines.h"
#include "GameManager.h"
#include "OptionMenu.h"
#include "CharacterSelectionMenu.h"


MainMenu::MainMenu(void) : Menu()
{
	Button * button;
	this->listButtons->push_back(new Button("New Game", new Position(POSITION_NEW_GAME_X, POSITION_NEW_GAME_Y), true, true, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionNewGame);
	button->setActionMove(&Menu::classicMove);
	this->listButtons->push_back(new Button("Option", new Position(POSITION_OPTION_X, POSITION_OPTION_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionGoToOption);
	button->setActionMove(&Menu::classicMove);
	this->listButtons->push_back(new Button("Exit", new Position(POSITION_EXIT_X, POSITION_EXIT_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionExit);
	button->setActionMove(&Menu::classicMove);

	this->spriteMenu->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(FILE_MENU));
}

MainMenu::~MainMenu(void)
{
}

void MainMenu::actionExit(Button * button)
{
    GameManager::getInstance()->stopTheGame();
}

void MainMenu::actionGoToOption(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new OptionMenu());
}

void MainMenu::actionNewGame(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new CharacterSelectionMenu());
}
