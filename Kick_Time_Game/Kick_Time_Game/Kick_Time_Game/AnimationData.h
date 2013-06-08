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

#define NUMBER_ANIMATIONDATA 20

extern const AnimationData animationDataArray[NUMBER_ANIMATIONDATA];

#define SCORPION_STAND_RIGHT 0
#define SCORPION_VICTORY 1
#define SCORPION_FORWARD_RIGHT 2
#define SCORPION_BACKWARD_RIGHT 3
#define SCORPION_STOOP_RIGHT 4
#define SCORPION_PICKUP_RIGHT 5
#define SCORPION_JUMPUP_RIGHT 6
#define SCORPION_JUMP_RIGHT 7
#define SCORPION_PUNCHRIGHT_RIGHT 8
#define SCORPION_PUNCHLEFT_RIGHT 9
#define SCORPION_KICKRIGHT_RIGHT 10
#define SCORPION_KICKLEFT_RIGHT 11
#define SCORPION_KICKJUMP_RIGHT 12
#define SCORPION_KICKDOWN_RIGHT 13
#define SCORPION_BLOCKING_RIGHT 14
#define SCORPION_BLOCKINGDOWN_RIGHT 15
#define SCORPION_HIT_RIGHT 16
#define SCORPION_HITDOWN_RIGHT 17
#define SUB_ZERO_STAND_RIGHT 18
#define SUB_ZERO_STAND_LEFT 19

#endif _ANIMATIONDATA_H
