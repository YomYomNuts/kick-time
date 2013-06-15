#ifndef _HUDMANAGER_H
#define _HUDMANAGER_H

#include <SFML/Graphics.hpp>

class HudManager
{
private:
	sf::Sprite * spriteHUD;
	bool doRenderHUDTime;
	void renderHUDTime();
	void renderHUDCharacter();
	void renderHUDLevel();

public:
	HudManager(void);
	~HudManager(void);
	void initializeHudManager();
	void updateHudManager();
	void renderHudManager();
	void setDoRenderHUDTime(bool active);
};

#endif