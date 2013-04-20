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
public:
	GameManager(void);
	~GameManager(void);
	void InitializeGameManager();
	void UpdateGameManager();
};

#endif