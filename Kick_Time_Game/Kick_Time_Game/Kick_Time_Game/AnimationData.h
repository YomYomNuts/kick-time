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

#define NUMBER_ANIMATIONDATA 39

extern const AnimationData animationDataArray[NUMBER_ANIMATIONDATA];

#define SCORPION_STAND_RIGHT 0
#define SCORPION_STAND_LEFT 1
#define SCORPION_FORWARD_RIGHT 2
#define SCORPION_FORWARD_LEFT 3
#define SCORPION_BACKWARD_RIGHT 4
#define SCORPION_BACKWARD_LEFT 5
#define SCORPION_CROUCH_RIGHT 6
#define SCORPION_CROUCH_LEFT 7
#define SCORPION_STANDUP_RIGHT 8
#define SCORPION_STANDUP_LEFT 9
#define SCORPION_STEADY_JUMP_UP_RIGHT 10
#define SCORPION_STEADY_JUMP_UP_LEFT 11
#define SCORPION_STEADY_JUMP_DOWN_RIGHT 12
#define SCORPION_STEADY_JUMP_DOWN_LEFT 13
#define SCORPION_FORWARD_JUMP_RIGHT 14
#define SCORPION_FORWARD_JUMP_LEFT 15
#define SCORPION_GUARD_RIGHT 16
#define SCORPION_GUARD_LEFT 17
#define SCORPION_LOW_GUARD_RIGHT 18
#define SCORPION_LOW_GUARD_LEFT 19
#define SCORPION_PUNCH_RIGHT 20
#define SCORPION_PUNCH_LEFT 21
#define SCORPION_KICK_RIGHT 22
#define SCORPION_KICK_LEFT 23
#define SCORPION_CROUCHED_KICK_RIGHT 24
#define SCORPION_CROUCHED_KICK_LEFT 25
#define SCORPION_CROUCHED_PUNCH_RIGHT 26
#define SCORPION_CROUCHED_PUNCH_LEFT 27
#define SCORPION_JUMPED_PUNCH_RIGHT 28
#define SCORPION_JUMPED_PUNCH_LEFT 29
#define SCORPION_JUMPED_KICK_RIGHT 30
#define SCORPION_JUMPED_KICK_LEFT 31
#define SCORPION_HIT_RIGHT 32
#define SCORPION_HIT_LEFT 33
#define SCORPION_LOW_HIT_RIGHT 34
#define SCORPION_LOW_HIT_LEFT 35
#define SCORPION_VICTORY 36
#define SUB_ZERO_STAND_RIGHT 37
#define SUB_ZERO_STAND_LEFT 38

#endif _ANIMATIONDATA_H
