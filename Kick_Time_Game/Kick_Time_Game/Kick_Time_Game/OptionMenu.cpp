#include "OptionMenu.h"
#include "OptionMenu_Defines.h"
#include "GameManager.h"
#include "SoundManager.h"
#include "SoundManager_Defines.h"
#include "Button_Defines.h"
#include "MainMenu.h"
#include "InputMenu.h"


OptionMenu::OptionMenu(void) : Menu()
{
	Button * button;
	this->listButtons->push_back(new Button("SFX", new Position(POSITION_VOLUME_SOUND_X, POSITION_VOLUME_SOUND_Y), true, true, true, 0));
    button = this->listButtons->at(this->listButtons->size() - 1);
	button->setActionMove(&Menu::volumeSoundMove);
	this->listButtons->push_back(new Button("Music", new Position(POSITION_VOLUME_MUSIC_X, POSITION_VOLUME_MUSIC_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setActionMove(&Menu::volumeMusicMove);
	this->listButtons->push_back(new Button("Change Inputs", new Position(POSITION_CHANGE_INPUTS_X, POSITION_CHANGE_INPUTS_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionGoToChangeInputs);
	button->setActionMove(&Menu::classicMove);
	this->listButtons->push_back(new Button("Back", new Position(POSITION_BACK_X, POSITION_BACK_Y), true, false, true, 0));
	button = this->listButtons->at(this->listButtons->size() - 1);
	button->setAction(&Menu::actionBack);
	button->setActionMove(&Menu::classicMove);

	// Set the render
	this->renderVolumeSound = new sf::Text("", *(GameManager::getInstance()->getFontManager()->getFont(BUTTON_FONT)));
	this->renderVolumeSound->setScale((float)BAR_SCALE_X, (float)BAR_SCALE_Y);
	this->renderVolumeSound->setPosition((float)(POSITION_BAR_SOUND_X), (float)(POSITION_BAR_SOUND_Y));
	this->renderVolumeMusic = new sf::Text("", *(GameManager::getInstance()->getFontManager()->getFont(BUTTON_FONT)));
	this->renderVolumeMusic->setScale((float)BAR_SCALE_X, (float)BAR_SCALE_Y);
	this->renderVolumeMusic->setPosition((float)(POSITION_BAR_MUSIC_X), (float)(POSITION_BAR_MUSIC_Y));

	this->spriteMenu->setTexture(*GameManager::getInstance()->getTextureManager()->getTexture(FILE_MENU));
}

OptionMenu::~OptionMenu(void)
{
	delete this->renderVolumeSound;
	delete this->renderVolumeMusic;
}

void OptionMenu::renderMenu()
{
	Menu::renderMenu();

	// Render the volume sound
    SoundManager * soundManager = GameManager::getInstance()->getSoundManager();
    string tempString = "";
    for (int i = 1; i <= NUMBER_SLOT_VOLUME; ++i)
    {
        if (i <= (int)((soundManager->getVolumeSound() * NUMBER_SLOT_VOLUME) / MAX_VOLUME))
            tempString += "|";
        else
            tempString += ".";
    }
	this->renderVolumeSound->setString(tempString);
	if (this->listButtons->at(0)->getIsActive())
		this->renderVolumeSound->setColor(sf::Color(BUTTON_ACTIVE_COLOR_RED, BUTTON_ACTIVE_COLOR_GREEN, BUTTON_ACTIVE_COLOR_BLUE));
	else
		this->renderVolumeSound->setColor(sf::Color(BUTTON_COLOR_RED, BUTTON_COLOR_GREEN, BUTTON_COLOR_BLUE));
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->renderVolumeSound);

	// Render the volume music
	tempString = "";
    for (int i = 1; i <= NUMBER_SLOT_VOLUME; ++i)
    {
        if (i <= (int)((soundManager->getVolumeMusic() * NUMBER_SLOT_VOLUME) / MAX_VOLUME))
            tempString += "|";
        else
            tempString += ".";
    }
	this->renderVolumeMusic->setString(tempString);
	if (this->listButtons->at(1)->getIsActive())
		this->renderVolumeMusic->setColor(sf::Color(BUTTON_ACTIVE_COLOR_RED, BUTTON_ACTIVE_COLOR_GREEN, BUTTON_ACTIVE_COLOR_BLUE));
	else
		this->renderVolumeMusic->setColor(sf::Color(BUTTON_COLOR_RED, BUTTON_COLOR_GREEN, BUTTON_COLOR_BLUE));
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(*this->renderVolumeMusic);
}

void OptionMenu::actionBack(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new MainMenu());
}

void OptionMenu::volumeSoundMove(Button * button, ButtonDirection direction)
{
	switch (direction)
	{
	case BUTTON_DIRECTION_UP:
	case BUTTON_DIRECTION_DOWN:
		{
			Button * nextButton = Menu::getNextButton(button, direction, false);
			if (nextButton != NULL)
			{
				button->setIsActive(false);
				nextButton->setIsActive(true);
			}
		}
		break;
	case BUTTON_DIRECTION_LEFT:
	    {
	        SoundManager * soundManager = GameManager::getInstance()->getSoundManager();
	        soundManager->setVolumeSound(soundManager->getVolumeSound() - MAX_VOLUME / NUMBER_SLOT_VOLUME);
	    }
        break;
	case BUTTON_DIRECTION_RIGHT:
	    {
	        SoundManager * soundManager = GameManager::getInstance()->getSoundManager();
	        soundManager->setVolumeSound(soundManager->getVolumeSound() + MAX_VOLUME / NUMBER_SLOT_VOLUME);
	    }
		break;
	}
}

void OptionMenu::volumeMusicMove(Button * button, ButtonDirection direction)
{
	switch (direction)
	{
	case BUTTON_DIRECTION_UP:
	case BUTTON_DIRECTION_DOWN:
		{
			Button * nextButton = Menu::getNextButton(button, direction, false);
			if (nextButton != NULL)
			{
				button->setIsActive(false);
				nextButton->setIsActive(true);
			}
		}
		break;
	case BUTTON_DIRECTION_LEFT:
	    {
	        SoundManager * soundManager = GameManager::getInstance()->getSoundManager();
	        soundManager->setVolumeMusic(soundManager->getVolumeMusic() - MAX_VOLUME / NUMBER_SLOT_VOLUME);
	    }
        break;
	case BUTTON_DIRECTION_RIGHT:
	    {
	        SoundManager * soundManager = GameManager::getInstance()->getSoundManager();
	        soundManager->setVolumeMusic(soundManager->getVolumeMusic() + MAX_VOLUME / NUMBER_SLOT_VOLUME);
	    }
		break;
	}
}

void OptionMenu::actionGoToChangeInputs(Button * button)
{
	GameManager::getInstance()->getMenuManager()->setActiveMenu(new InputMenu());
}
