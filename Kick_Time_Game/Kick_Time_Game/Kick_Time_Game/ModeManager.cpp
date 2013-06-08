#include "ModeManager.h"

#include <stdio.h>


ModeManager::ModeManager(void)
{
	this->activeMode = NULL;
}

ModeManager::~ModeManager(void)
{
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
	this->activeMode = mode;
}

Mode * ModeManager::getActiveMode()
{
	return this->activeMode;
}
