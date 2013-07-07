#include "InputManager.h"
#include "GameManager_Defines.h"


InputManager::InputManager(void)
{
    this->listInputCharacter = new vector<InputCharacter*>();
}

InputManager::~InputManager(void)
{
    delete this->listInputCharacter;
}

void InputManager::initializeInputManager()
{
    for (int i = 0; i < NUMBER_FIGHTERS; ++i)
        this->listInputCharacter->push_back(new InputCharacter());

	//Input Player 1
	vector<sf::Keyboard::Key> * listInputs = new vector<sf::Keyboard::Key>();
	listInputs->push_back(sf::Keyboard::Z);
	listInputs->push_back(sf::Keyboard::S);
	listInputs->push_back(sf::Keyboard::Q);
	listInputs->push_back(sf::Keyboard::D);
	listInputs->push_back(sf::Keyboard::I);
	listInputs->push_back(sf::Keyboard::J);
	listInputs->push_back(sf::Keyboard::K);
	listInputs->push_back(sf::Keyboard::L);
	this->listInputCharacter->at(0)->setListInputs(listInputs);

	//Input Player 2
	vector<sf::Keyboard::Key> * listInputs2 = new vector<sf::Keyboard::Key>();
	listInputs2->push_back(sf::Keyboard::Up);
	listInputs2->push_back(sf::Keyboard::Down);
	listInputs2->push_back(sf::Keyboard::Left);
	listInputs2->push_back(sf::Keyboard::Right);
	listInputs2->push_back(sf::Keyboard::Num5);
	listInputs2->push_back(sf::Keyboard::Num1);
	listInputs2->push_back(sf::Keyboard::Num2);
	listInputs2->push_back(sf::Keyboard::Num3);
	this->listInputCharacter->at(1)->setListInputs(listInputs2);
}

void InputManager::updateInputManager()
{
}

bool InputManager::isPressed(int indexPlayer, int indexAction)
{
    return this->listInputCharacter->at(indexPlayer)->isPressed(indexAction);
}
