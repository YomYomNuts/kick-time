#ifndef __ANIMATIONLINE__
#define __ANIMATIONLINE__

#include <iostream>
using namespace std;

class AnimationLine{

private:
	char* fileName;
	char* animationName;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	bool animationLoop;

public:
	AnimationLine(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);
	char* getFileName();
	char* getAnimationName();
	int getPosX();
	int getPosY();
	int getSpriteWidth();
	int getSpriteHeight();
	int getFramerate();
	int getSpriteNb();
	bool getAnimationLoop();
};

#endif __ANIMATIONLINE__