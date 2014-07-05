#include "ModeManager.h"

#include <stdio.h>


ModeManager::ModeManager(void)
{
	this->activeMode = NULL;
}

ModeManager::~ModeManager(void)
{
    if (this->activeMode != NULL)
        delete this->activeMode;
}

void ModeManager::initializeModeManager()
{
}

void ModeManager::updateModeManager()
{
	if (this->activeMode != NULL)
		this->activeMode->updateMode();
}

void ModeManager::setActiveMode(Mode * mode)
{
    if (this->activeMode != NULL)
        delete this->activeMode;
	this->activeMode = mode;
}

Mode * ModeManager::getActiveMode()
{
	return this->activeMode;
}
