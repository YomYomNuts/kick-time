#ifndef _ANIMATIONDATA_H
#define _ANIMATIONDATA_H

#include <string>

using namespace std;

class AnimationData
{
private:
	string fileName;
	int animationName;
	int posX;
	int posY;
	int spriteWidth;
	int spriteHeight;
	int framerate;
	int spriteNb;
	bool animationLoop;
public:
	AnimationData();
	AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);
	~AnimationData(void);
	string getFileName() const;
	int getAnimationName() const;
	int getPosX() const;
	int getPosY() const;
	int getSpriteWidth() const;
	int getSpriteHeight() const;
	int getFramerate() const;
	int getSpriteNb() const;
	bool getAnimationLoop() const;
};

#define NUMBER_ANIMATIONDATA 5

extern const AnimationData animationDataArray[NUMBER_ANIMATIONDATA];

#define SCORPION_STAND_RIGHT 0
#define SCORPION_STAND_LEFT 1
#define SCORPION_KICK_LEFT 2
#define SUB_ZERO_STAND_RIGHT 3
#define SUB_ZERO_STAND_LEFT 4

#endif _ANIMATIONDATA_H
