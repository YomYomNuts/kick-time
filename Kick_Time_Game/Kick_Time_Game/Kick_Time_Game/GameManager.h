#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "ModeManager.h"
#include "SaveManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "MenuManager.h"
#include "HudManager.h"
#include "RenderManager.h"
#include "LevelManager.h"
#include "CharacterManager.h"
#include "AnimationManager.h"
#include "GameManager_Defines.h"

class GameManager
{
private:
	ModeManager * modeManager;
	SaveManager * saveManager;
	InputManager * inputManager;
	SoundManager * soundManager;
	MenuManager * menuManager;
	HudManager * hudManager;
	RenderManager * renderManager;
	LevelManager * levelManager;
	CharacterManager * characterManager;
	AnimationManager * animationManager;
	static GameManager  * _singleton;
	GameManager(void);
public:
	~GameManager(void);
	static GameManager* getInstance();
	void initializeGameManager();
	void updateGameManager();
	ModeManager* getModeManager();
	SaveManager* getSaveManager();
	InputManager* getInputManager();
	SoundManager* getSoundManager();
	MenuManager* getMenuManager();
	HudManager* getHudManager();
	RenderManager* getRenderManager();
	LevelManager* getLevelManager();
	CharacterManager* getCharacterManager();
	AnimationManager* getAnimationManager();
};

#endif