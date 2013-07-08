#ifndef _OPTIONMENU_H
#define _OPTIONMENU_H

#include "Menu.h"

#include <SFML/Graphics.hpp>

class OptionMenu : public Menu
{
private:
	sf::Text * renderVolumeSound;
	sf::Text * renderVolumeMusic;
protected:
	Button * getNextButton(Button * buttonCurrent, ButtonDirection direction);
public:
	OptionMenu(void);
	~OptionMenu(void);
	void renderMenu();
	void actionBack(Button * button);
    void volumeSoundMove(Button * button, ButtonDirection direction);
    void volumeMusicMove(Button * button, ButtonDirection direction);
	void actionGoToChangeInputs(Button * button);
};

#endif
