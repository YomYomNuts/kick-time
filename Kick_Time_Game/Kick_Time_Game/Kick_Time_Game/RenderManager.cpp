#include "RenderManager.h"
#include "GameManager.h"

RenderManager::RenderManager(void)
{
	this->window = new sf::RenderWindow();
}

RenderManager::~RenderManager(void)
{
}

void RenderManager::initializeRenderManager()
{
	this->window->create(sf::VideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT), "Kick-Time");
	this->window->setFramerateLimit(60);
}

void RenderManager::updateRenderManager()
{
	// Close the window
	sf::Event event;
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
			this->window->close();
    }


    this->window->clear();
	GameManager::getInstance()->getLevelManager()->renderLevelManager();
	GameManager::getInstance()->getCharacterManager()->renderCharacterManager();
    window->display();
}
sf::RenderWindow* RenderManager::getWindow()
{
	return this->window;
}