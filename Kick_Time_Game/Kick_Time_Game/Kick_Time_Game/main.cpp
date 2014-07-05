#include "GameManager.h"
#include "AnimationCharacter.h"
#include "AnimationLevel.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;

GameManager * GameManager::_singleton = NULL;
int AnimationCharacter::animationNumber = 0;
int AnimationLevel::animationNumber = 0;

int main()
{
	GameManager * gameManager = GameManager::getInstance();
	gameManager->initializeGameManager();
	gameManager->updateGameManager();
    delete gameManager;

    return 0;
}
