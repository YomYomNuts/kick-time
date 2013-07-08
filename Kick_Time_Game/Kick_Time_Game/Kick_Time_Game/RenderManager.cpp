#include "RenderManager.h"
#include "GameManager.h"

RenderManager::RenderManager(void)
{
	this->window = new sf::RenderWindow();
	this->event = new sf::Event();
}

RenderManager::~RenderManager(void)
{
	delete this->window;
	delete this->event;
}

void RenderManager::initializeRenderManager()
{
	this->window->create(sf::VideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT), "Kick-Time");
	this->window->setFramerateLimit(NUMBER_FRAME_PER_SECOND);
}

void RenderManager::updateRenderManager()
{
	// Close the window
    while (this->window->pollEvent(*this->event))
    {
        if (this->event->type == sf::Event::Closed)
			this->window->close();
    }


    this->window->clear();
	GameManager::getInstance()->getMenuManager()->renderMenuManager();
	GameManager::getInstance()->getLevelManager()->renderLevelManager();
	GameManager::getInstance()->getCharacterManager()->renderCharacterManager();
	GameManager::getInstance()->getHudManager()->renderHudManager();
    window->display();
}

sf::RenderWindow* RenderManager::getWindow()
{
	return this->window;
}

sf::Event* RenderManager::getEvent()
{
    return this->event;
}
