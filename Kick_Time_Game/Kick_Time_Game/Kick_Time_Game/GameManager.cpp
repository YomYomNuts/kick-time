#include "GameManager.h"


GameManager::GameManager(void)
{
	this->stopGame = false;
	this->modeManager = new ModeManager();
	this->saveManager = new SaveManager();
	this->inputManager = new InputManager();
	this->soundManager = new SoundManager();
	this->menuManager = new MenuManager();
	this->hudManager = new HudManager();
	this->renderManager = new RenderManager();
	this->levelManager = new LevelManager();
	this->characterManager = new CharacterManager();
	this->animationManager = new AnimationManager();
	this->textureManager = new TextureManager();
	this->fontManager = new FontManager();
}

GameManager::~GameManager(void)
{
	delete this->modeManager;
	delete this->saveManager;
	delete this->inputManager;
	delete this->soundManager;
	delete this->menuManager;
	delete this->hudManager;
	delete this->renderManager;
	delete this->levelManager;
	delete this->characterManager;
	delete this->animationManager;
	delete this->textureManager;
	delete this->fontManager;
}

GameManager* GameManager::getInstance()
{
	if (GameManager::_singleton == NULL)
		GameManager::_singleton =  new GameManager();

	return GameManager::_singleton;
}

void GameManager::initializeGameManager()
{
	this->fontManager->initializeFontManager();
	this->textureManager->initializeTextureManager();
	this->modeManager->initializeModeManager();
	this->inputManager->initializeInputManager();
	this->menuManager->initializeMenuManager();
	this->soundManager->initializeSoundManager();
	this->saveManager->initializeSaveManager();
	this->levelManager->initializeLevelManager();
	this->hudManager->initializeHudManager();
	this->renderManager->initializeRenderManager();
	this->characterManager->initializeCharacterManager();
	this->animationManager->initializeAnimationManager();
}

void GameManager::updateGameManager()
{
    while (this->renderManager->getWindow()->isOpen() && !this->stopGame)
	{
		this->fontManager->updateFontManager();
		this->textureManager->updateTextureManager();
		this->inputManager->updateInputManager();
		this->menuManager->updateMenuManager();
		this->modeManager->updateModeManager();
		this->levelManager->updateLevelManager();
		this->characterManager->updateCharacterManager();
		this->soundManager->updateSoundManager();
		this->saveManager->updateSaveManager();
		this->hudManager->updateHudManager();
		this->animationManager->updateAnimationManager();
		this->renderManager->updateRenderManager();
	}
}

void GameManager::stopTheGame()
{
    this->stopGame = true;
}

ModeManager* GameManager::getModeManager()
{
	return this->modeManager;
}

SaveManager* GameManager::getSaveManager()
{
	return this->saveManager;
}

InputManager* GameManager::getInputManager()
{
	return this->inputManager;
}

SoundManager* GameManager::getSoundManager()
{
	return this->soundManager;
}

MenuManager* GameManager::getMenuManager()
{
	return this->menuManager;
}

HudManager* GameManager::getHudManager()
{
	return this->hudManager;
}

RenderManager* GameManager::getRenderManager()
{
	return this->renderManager;
}

LevelManager* GameManager::getLevelManager()
{
	return this->levelManager;
}

CharacterManager* GameManager::getCharacterManager()
{
	return this->characterManager;
}

AnimationManager* GameManager::getAnimationManager()
{
	return this->animationManager;
}

TextureManager* GameManager::getTextureManager()
{
	return this->textureManager;
}

FontManager* GameManager::getFontManager()
{
	return this->fontManager;
}
