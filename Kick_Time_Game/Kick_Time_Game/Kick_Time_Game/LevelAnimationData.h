#ifndef _LEVELANIMATIONDATA_H
#define _LEVELANIMATIONDATA_H

#include <string>
#include "AnimationData.h"
#include "Position.h"

using namespace std;

class LevelAnimationData:public AnimationData
{
private:
	Position * animPosition;
public:
	LevelAnimationData(void);
	LevelAnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int shiftPositionXCharacter, int colliderID, int colliderKickPunchID, double posAnimX, double posAnimY);
	~LevelAnimationData(void);
	double getAnimPosX() const;
	double getAnimPosY() const;
};

#endif _LEVELANIMATIONDATA_H

