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
public:
	AnimationLine::AnimationLine();
	AnimationLine(string fileName, string animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);
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
};

#endif __ANIMATIONLINE__