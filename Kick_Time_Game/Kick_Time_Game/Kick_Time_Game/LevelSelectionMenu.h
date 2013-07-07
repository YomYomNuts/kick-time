#ifndef _LEVELSELECTIONMENU_H
#define _LEVELSELECTIONMENU_H

#include "Menu.h"

#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

class LevelSelectionMenu : public Menu
{
private:
    vector<sf::Sprite *> * listLevelsSprites;
public:
    LevelSelectionMenu();
    ~LevelSelectionMenu();
	void renderMenu();
	void actionBack(Button * button);
	void actionValidateLevel(Button * button);
};

#endif // _LEVELSELECTIONMENU_H
