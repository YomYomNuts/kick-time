#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Mode.h"
#include "SaveManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "MenuManager.h"
#include "HudManager.h"
#include "RenderManager.h"
#include "Level.h"
#include "Character.h"
#include "GameManager_Defines.h"

#include <vector>

class GameManager
{
private:
	std::vector<Mode> listModes;
	SaveManager saveManager;
	InputManager inputManager;
	SoundManager soundManager;
	MenuManager menuManager;
	HudManager hudManager;
	RenderManager renderManager;
	std::vector<Level> listLevels;
	std::vector<Character> listCharacters;
	Mode * modeSelected;
	Level * levelSelected;
	Character * characterSelected[NUMBER_CHARACTERS];
public:
	GameManager(void);
	~GameManager(void);
	void InitializeGameManager();
	void UpdateGameManager();
};

#endif