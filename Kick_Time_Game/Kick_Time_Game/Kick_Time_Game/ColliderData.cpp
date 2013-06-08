#include "ColliderData.h"

const ColliderData colliderDataArray[NUMBER_COLLIDERDATA] =
{
	ColliderData(COLLIDER_SCORPION_STAND_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_VICTORY, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_FORWARD_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_BACKWARD_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_STOOP_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_PICKUP_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_JUMPUP_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_JUMP_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_PUNCHRIGHT_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_PUNCHLEFT_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_KICKRIGHT_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_KICKLEFT_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_KICKJUMP_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_KICKDOWN_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_BLOCKING_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_BLOCKINGDOWN_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_HIT_RIGHT, 10, 10, 10, 30),
	ColliderData(COLLIDER_SCORPION_HITDOWN_RIGHT, 10, 10, 10, 30),
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
