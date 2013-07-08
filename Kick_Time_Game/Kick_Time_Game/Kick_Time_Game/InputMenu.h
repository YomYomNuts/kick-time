#ifndef INPUTMENU_H
#define INPUTMENU_H

#include "Menu.h"

class InputMenu : public Menu
{
private:
	vector<Button*> * listButtonsInformations;
	vector<bool> * listInputsChange;
public:
    InputMenu();
    ~InputMenu();
	void updateMenu();
	void renderMenu();
	void actionBack(Button * button);
	void actionChangeInputs(Button * button);
	void applyChangeInputs(Button * button, int indexButton);
};

#endif // INPUTMENU_H
