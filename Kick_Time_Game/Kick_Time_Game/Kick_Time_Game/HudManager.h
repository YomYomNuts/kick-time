#ifndef _HUDMANAGER_H
#define _HUDMANAGER_H

#include <SFML/Graphics.hpp>

class HudManager
{
private:
	sf::Sprite * spriteHUD;
	bool doRenderLifeBar;
	bool doRenderTime;
	void renderLifeBar(int indexCharacter);
	void renderTime();

public:
	HudManager(void);
	~HudManager(void);
	void initializeHudManager();
	void updateHudManager();
	void renderHudManager();
};

#endif