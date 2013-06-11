#ifndef _ANIMATIONLINE_H
#define _ANIMATIONLINE_H

#include <string>

using namespace std;

class AnimationLine
{
private:
	string fileName;
	string animationName;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	bool animationLoop;
	int shiftPositionXCharacter;
	string colliderName;
	string colliderKickPunchName;
public:
	AnimationLine();
	AnimationLine(string fileName, string animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int shiftPositionXCharacter, string colliderName, string colliderKickPunchName);
	~AnimationLine(void);
	string getFileName();
	string getAnimationName();
	int getPosX();
	int getPosY();
	int getSpriteWidth();
	int getSpriteHeight();
	int getFramerate();
	int getSpriteNb();
	bool getAnimationLoop();
	int getShiftPositionXCharacter();
	string getColliderName();
	string getColliderKickPunchName();
};

#endif _ANIMATIONLINE_H