#include "GameManager.h"


GameManager::GameManager(void)
{
	this->listModes = new std::vector<Mode>();
	this->saveManager = new SaveManager();
	this->inputManager = new InputManager();
	this->soundManager = new SoundManager();
	this->menuManager = new MenuManager();
	this->hudManager = new HudManager();
	this->renderManager = new RenderManager();
	this->listLevels = new std::vector<Level>();
	this->listCharacters = new std::vector<Character>();
	this->modeSelected = NULL;
	this->levelSelected = NULL;
	for(int index = 0; index < NUMBER_CHARACTERS; ++i)
		this->characterSelected[index] = NULL;
}

GameManager::~GameManager(void)
{
	delete[] this->modeSelected;
	delete[] this->levelSelected;
	for(int index = 0; index < NUMBER_CHARACTERS; ++i)
		delete[] this->characterSelected[index];
}

void GameManager::InitializeGameManager()
{
	this->inputManager.InitializeInputManager();
	this->menuManager.InitializeMenuManager();
	this->soundManager.InitializeSoundManager();
	this->saveManager.InitializeSaveManager();
	this->hudManager.InitializeHudManager();
	this->renderManager.InitializeRenderManager();
}

void GameManager::UpdateGameManager()
{
	this->inputManager.UpdateInputManager();
	this->menuManager.UpdateMenuManager();
	this->soundManager.UpdateSoundManager();
	this->saveManager.UpdateSaveManager();
	this->hudManager.UpdateHudManager();
	this->renderManager.UpdateRenderManager();
}