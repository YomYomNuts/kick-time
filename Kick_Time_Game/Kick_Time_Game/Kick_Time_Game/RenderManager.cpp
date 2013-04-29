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
    window->clear();
	GameManager::getInstance()->getLevelManager()->RenderLevelManager();
    window->display();
}
sf::RenderWindow* RenderManager::getWindow()
{
	return this->window;
}