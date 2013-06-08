#ifndef _MODEMANAGER_H
#define _MODEMANAGER_H

#include "Mode.h"

class ModeManager
{
private:
	Mode * activeMode;

public:
	ModeManager(void);
	~ModeManager(void);
	void initializeModeManager();
	void updateModeManager();
	void setActiveMode(Mode * mode);
	Mode * getActiveMode();
};

#endif