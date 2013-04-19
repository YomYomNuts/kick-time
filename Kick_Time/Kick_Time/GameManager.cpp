#include "GameManager.h"


GameManager::GameManager(void)
{
	this->modeManager = new ModeManager();
	this->saveManager = new SaveManager();
	this->inputManager = new InputManager();
	this->soundManager = new SoundManager();
	this->menuManager = new MenuManager();
	this->hudManager = new HudManager();
	this->renderManager = new RenderManager();
	this->levelManager = new LevelManager();
	this->characterManager = new CharacterManager();
}

GameManager::~GameManager(void)
{
}

void GameManager::InitializeGameManager()
{
	this->modeManager.InitializeModeManager();
	this->inputManager.InitializeInputManager();
	this->menuManager.InitializeMenuManager();
	this->soundManager.InitializeSoundManager();
	this->saveManager.InitializeSaveManager();
	this->hudManager.InitializeHudManager();
	this->renderManager.InitializeRenderManager();
	this->levelManager.InitializeLevelManager();
	this->characterManager.InitializeCharacterManager();
}

void GameManager::UpdateGameManager()
{
	this->inputManager.UpdateInputManager();
	this->menuManager.UpdateMenuManager();
	this->modeManager.UpdateModeManager();
	this->levelManager.UpdateLevelManager();
	this->characterManager.UpdateCharacterManager();
	this->soundManager.UpdateSoundManager();
	this->saveManager.UpdateSaveManager();
	this->hudManager.UpdateHudManager();
	this->renderManager.UpdateRenderManager();
}