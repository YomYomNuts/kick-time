#ifndef _COLLIDERDATA_H
#define _COLLIDERDATA_H

#include <string>

using namespace std;

class ColliderData
{
private:
	int colliderID;
	int posX;
	int posY;
	int halfSizeX;
	int halfSizeY;

public:
	ColliderData();
	ColliderData(int colliderID, int posX, int posY, int halfSizeX, int halfSizeY);
	~ColliderData(void);
	int getColliderID() const;
	int getPosX() const;
	int getPosY() const;
	int getHalfSizeX() const;
	int getHalfSizeY() const;
};

#define NUMBER_COLLIDERDATA 18

extern const ColliderData colliderDataArray[NUMBER_COLLIDERDATA];

#define COLLIDER_NULL (-1)
#define COLLIDER_SCORPION_STAND_RIGHT 0
#define COLLIDER_SCORPION_VICTORY 1
#define COLLIDER_SCORPION_FORWARD_RIGHT 2
#define COLLIDER_SCORPION_BACKWARD_RIGHT 3
#define COLLIDER_SCORPION_STOOP_RIGHT 4
#define COLLIDER_SCORPION_PICKUP_RIGHT 5
#define COLLIDER_SCORPION_JUMPUP_RIGHT 6
#define COLLIDER_SCORPION_JUMP_RIGHT 7
#define COLLIDER_SCORPION_PUNCHRIGHT_RIGHT 8
#define COLLIDER_SCORPION_PUNCHLEFT_RIGHT 9
#define COLLIDER_SCORPION_KICKRIGHT_RIGHT 10
#define COLLIDER_SCORPION_KICKLEFT_RIGHT 11
#define COLLIDER_SCORPION_KICKJUMP_RIGHT 12
#define COLLIDER_SCORPION_KICKDOWN_RIGHT 13
#define COLLIDER_SCORPION_BLOCKING_RIGHT 14
#define COLLIDER_SCORPION_BLOCKINGDOWN_RIGHT 15
#define COLLIDER_SCORPION_HIT_RIGHT 16
#define COLLIDER_SCORPION_HITDOWN_RIGHT 17

#endif _COLLIDERDATA_H
