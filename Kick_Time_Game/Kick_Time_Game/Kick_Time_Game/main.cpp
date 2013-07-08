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

	/*
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
    sf::CircleShape greenCircle(100.f);
	sf::CircleShape redCircle(100.f);
    greenCircle.setFillColor(sf::Color::Green);
	redCircle.setFillColor(sf::Color::Red);
	redCircle.setPosition(10.f,0.f);

	sf::Font MyFont;

	// Chargement à partir d'un fichier sur le disque
	if (!MyFont.loadFromFile("../Ressources/Fonts/arial.ttf"))
	{
		cout << "Unable to open font" << endl;
	}
	sf::Text text("pouet",MyFont);

	text.setColor(sf::Color(0,50,128));
	text.setRotation(-25.f);
	text.setScale(1.f, 1.f);
	text.move(100.f, 100.f);


	sf::Texture scorpionSheet;
	if (!scorpionSheet.loadFromFile("../Ressources/Characters/MK/Scorpion/Scorpion.png"))
	{
		cout << "Sprite didn't find!" << endl;
	}

	sf::Sprite scorpion;
	scorpion.setTexture(scorpionSheet);

	scorpion.setTextureRect(sf::IntRect(364,108,48,100));

	scorpion.setPosition(50,50);

	enum state{Stance,Punch};

	state persoState = Stance;
	int posXSprite = 364;
	int i = 1;
	int framerate=0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
				window.close();
        }

        window.clear();
        window.draw(redCircle);
		window.draw(greenCircle);
		window.draw(text);
		window.draw(scorpion);
        window.display();

		sf::Time frameTime;

		sf::Clock pf;
		frameTime = pf.restart();
		float pd = pf.getElapsedTime().asMilliseconds();

		if(framerate == 9){
			if(persoState == Stance){
				posXSprite = posXSprite + 48 + 14;
				i++;

				if(posXSprite > 590)
				{
					posXSprite = 364;
					i = 1;
				}

				scorpion.setTextureRect(sf::IntRect(posXSprite,108,48,100));
			}
			framerate = 0;
		}

		framerate++;


    }
	*/
    return 0;
}
