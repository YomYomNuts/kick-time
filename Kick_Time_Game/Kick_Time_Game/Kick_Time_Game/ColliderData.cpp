#include "ColliderData.h"

const ColliderData colliderDataArray[NUMBER_COLLIDERDATA] =
{
	ColliderData(COLLIDER_SCORPION_STAND_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_RIGHT_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_LEFT_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCH_RIGHT, 36, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STANDUP_RIGHT, 36, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_UP_RIGHT, 36, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_DOWN_RIGHT, 36, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_FORWARD_JUMP_RIGHT, 36, 100, 22, 30),
	ColliderData(COLLIDER_SCORPION_GUARD_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_GUARD_RIGHT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_PUNCH_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_KICK_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_KICK_RIGHT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_CROUCHED_PUNCH_RIGHT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_PUNCH_RIGHT, 36, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_KICK_RIGHT, 36, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_HIT_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_HIT_RIGHT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_VICTORY_RIGHT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_RIGHT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_STAND_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_RIGHT_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_MOVE_LEFT_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCH_LEFT, 36, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STANDUP_LEFT, 36, 55, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_UP_LEFT, 36, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_STEADY_JUMP_DOWN_LEFT, 36, 85, 22, 50),
	ColliderData(COLLIDER_SCORPION_FORWARD_JUMP_LEFT, 36, 100, 22, 30),
	ColliderData(COLLIDER_SCORPION_GUARD_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_GUARD_LEFT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_PUNCH_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_KICK_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_KICK_LEFT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_CROUCHED_PUNCH_LEFT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_PUNCH_LEFT, 36, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_JUMPED_KICK_LEFT, 36, 85, 22, 30),
	ColliderData(COLLIDER_SCORPION_HIT_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_LOW_HIT_LEFT, 36, 40, 22, 30),
	ColliderData(COLLIDER_SCORPION_VICTORY_LEFT, 36, 70, 22, 70),
	ColliderData(COLLIDER_SCORPION_CROUCHED_LEFT, 36, 40, 22, 30),
};

ColliderData::ColliderData()
{
	this->colliderID = 0;
	this->posX = 0;
	this->posY = 0;
	this->halfSizeX = 0;
	this->halfSizeY = 0;
}

ColliderData::ColliderData(int colliderID, int posX, int posY, int halfSizeX, int halfSizeY)
{
	this->colliderID = colliderID;
	this->posX = posX;
	this->posY = posY;
	this->halfSizeX = halfSizeX;
	this->halfSizeY = halfSizeY;
}

ColliderData::~ColliderData(void)
{
}

int ColliderData::getColliderID() const
{
	return this->colliderID;
}

int ColliderData::getPosX() const
{
	return this->posX;
}

int ColliderData::getPosY() const
{
	return this->posY;
}

int ColliderData::getHalfSizeX() const
{
	return this->halfSizeX;
}

int ColliderData::getHalfSizeY() const
{
	return this->halfSizeY;
}
