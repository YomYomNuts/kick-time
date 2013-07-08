#ifndef _RENDERMANAGER_H
#define _RENDERMANAGER_H

#include <SFML/Graphics.hpp>

class RenderManager
{
private:
	sf::RenderWindow * window;
	sf::Event * event;

public:
	RenderManager(void);
	~RenderManager(void);
	void initializeRenderManager();
	void updateRenderManager();
	sf::RenderWindow* getWindow();
	sf::Event* getEvent();
};

#endif
