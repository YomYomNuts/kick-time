#ifndef _ANIMATIONLINE_H
#define _ANIMATIONLINE_H

#include <string>

using namespace std;

class AnimationLine
{
private:
	int levelNumber;
	string fileName;
	int animationNumber;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	bool animationLoop;
	int posXAnim;
	int posYAnim;
public:
	AnimationLine();
	AnimationLine(int levelNumber, string fileName, int animationNumber, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int posXAnim, int posYAnim);
	~AnimationLine(void);
	string getFileName();
	int getAnimationNumber();
	int getPosX();
	int getPosY();
	int getSpriteWidth();
	int getSpriteHeight();
	int getFramerate();
	int getSpriteNb();
	bool getAnimationLoop();
	int getPosXAnim();
	int getPosYAnim();
	int getLevelNumber();
};

#endif _ANIMATIONLINE_H