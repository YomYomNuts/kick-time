#ifndef _CHARACTERSELECTIONMENU_H
#define _CHARACTERSELECTIONMENU_H

#include "Menu.h"

#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

class CharacterSelectionMenu : public Menu
{
private:
    vector<sf::Sprite *> * listAvatars;
    vector<bool> * listValidation;
public:
    CharacterSelectionMenu();
    ~CharacterSelectionMenu();
	void renderMenu();
	void actionBack(Button * button);
	void actionValidateCharacter(Button * button);
};

#endif // _CHARACTERSELECTIONMENU_H
