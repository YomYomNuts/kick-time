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
	int shiftPositionXCharacter;
	int colliderID;
	int colliderKickPunchID;

public:
	AnimationData();
	AnimationData(int s);
	AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int shiftPositionXCharacter, int colliderID, int colliderKickPunchID);
	AnimationData::AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop);
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
	int getShiftPositionXCharacter() const;
	int getColliderID() const;
	int getColliderKickPunchID() const;
};

#define NUMBER_ANIMATIONDATA 46

extern const AnimationData animationDataArray[NUMBER_ANIMATIONDATA];

#define SCORPION_STAND_RIGHT 0
#define SCORPION_MOVE_RIGHT_RIGHT 1
#define SCORPION_MOVE_LEFT_RIGHT 2
#define SCORPION_CROUCH_RIGHT 3
#define SCORPION_STANDUP_RIGHT 4
#define SCORPION_STEADY_JUMP_UP_RIGHT 5
#define SCORPION_STEADY_JUMP_DOWN_RIGHT 6
#define SCORPION_FORWARD_JUMP_RIGHT 7
#define SCORPION_BACKWARD_JUMP_RIGHT 8
#define SCORPION_GUARD_RIGHT 9
#define SCORPION_GUARD_ON_RIGHT 10
#define SCORPION_LOW_GUARD_RIGHT 11
#define SCORPION_LOW_GUARD_ON_RIGHT 12
#define SCORPION_PUNCH_RIGHT 13
#define SCORPION_KICK_RIGHT 14
#define SCORPION_CROUCHED_KICK_RIGHT 15
#define SCORPION_CROUCHED_PUNCH_RIGHT 16
#define SCORPION_JUMPED_PUNCH_RIGHT 17
#define SCORPION_JUMPED_KICK_RIGHT 18
#define SCORPION_HIT_RIGHT 19
#define SCORPION_LOW_HIT_RIGHT 20
#define SCORPION_VICTORY_RIGHT 21
#define SCORPION_CROUCHED_RIGHT 22
#define SCORPION_STAND_LEFT 23
#define SCORPION_MOVE_RIGHT_LEFT 24
#define SCORPION_MOVE_LEFT_LEFT 25
#define SCORPION_CROUCH_LEFT 26
#define SCORPION_STANDUP_LEFT 27
#define SCORPION_STEADY_JUMP_UP_LEFT 28
#define SCORPION_STEADY_JUMP_DOWN_LEFT 29
#define SCORPION_FORWARD_JUMP_LEFT 30
#define SCORPION_BACKWARD_JUMP_LEFT 31
#define SCORPION_GUARD_LEFT 32
#define SCORPION_GUARD_ON_LEFT 33
#define SCORPION_LOW_GUARD_LEFT 34
#define SCORPION_LOW_GUARD_ON_LEFT 35
#define SCORPION_PUNCH_LEFT 36
#define SCORPION_KICK_LEFT 37
#define SCORPION_CROUCHED_KICK_LEFT 38
#define SCORPION_CROUCHED_PUNCH_LEFT 39
#define SCORPION_JUMPED_PUNCH_LEFT 40
#define SCORPION_JUMPED_KICK_LEFT 41
#define SCORPION_HIT_LEFT 42
#define SCORPION_LOW_HIT_LEFT 43
#define SCORPION_VICTORY_LEFT 44
#define SCORPION_CROUCHED_LEFT 45

#endif _ANIMATIONDATA_H
