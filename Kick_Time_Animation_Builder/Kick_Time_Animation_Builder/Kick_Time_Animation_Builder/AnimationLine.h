#ifndef __ANIMATIONLINE__
#define __ANIMATIONLINE__

class AnimationLine
{
private:
	char* fileName;
	char* animationName;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	char* animationLoop;

public:
	AnimationLine::AnimationLine();
	AnimationLine(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, char* animationLoop);
	char* getFileName();
	char* getAnimationName();
	int getPosX();
	int getPosY();
	int getSpriteWidth();
	int getSpriteHeight();
	int getFramerate();
	int getSpriteNb();
	char* getAnimationLoop();
	~AnimationLine(void);
};

#endif __ANIMATIONLINE__