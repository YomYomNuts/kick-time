#include "AnimationData.h"
#include "ColliderData.h"

const AnimationData animationDataArray[NUMBER_ANIMATIONDATA] =
{
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STAND_RIGHT, 0, 0, 73, 138, 6, 7, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_FORWARD_RIGHT, 0, 142, 82, 145, 6, 9, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_BACKWARD_RIGHT, 0, 297, 73, 143, 6, 8, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCH_RIGHT, 0, 443, 68, 124, 3, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STANDUP_RIGHT, 0, 576, 68, 124, 3, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_UP_RIGHT, 0, 709, 77, 148, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_DOWN_RIGHT, 0, 865, 77, 148, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_FORWARD_JUMP_RIGHT, 0, 1019, 67, 146, 6, 8, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_GUARD_RIGHT, 0, 1166, 67, 140, 6, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_GUARD_RIGHT, 0, 1326, 69, 87, 6, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_PUNCH_RIGHT, 0, 1444, 143, 143, 6, 9, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_KICK_RIGHT, 0, 1601, 125, 142, 6, 7, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_KICK_RIGHT, 0, 1742, 114, 101, 6, 7, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_PUNCH_RIGHT, 0, 1871, 101, 97, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_PUNCH_RIGHT, 0, 1981, 148, 88, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_KICK_RIGHT, 0, 2092, 129, 96, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_HIT_RIGHT, 0, 2203, 79, 136, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_HIT_RIGHT, 0, 2348, 75, 94, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_VICTORY_RIGHT, 0, 2455, 58, 167, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_RIGHT, 0, 2634, 72, 86, 15, 2, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STAND_LEFT, 1912, 0, -73, 138, 6, 7, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_FORWARD_LEFT, 1912, 297, -73, 143, 6, 8, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_BACKWARD_LEFT, 1912, 142, -82, 145, 6, 9, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCH_LEFT, 1912, 443, -68, 124, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STANDUP_LEFT, 1912, 576, -68, 124, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_UP_LEFT, 1912, 709, -77, 148, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_STEADY_JUMP_DOWN_LEFT, 1912, 865, -77, 148, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_FORWARD_JUMP_LEFT, 1912, 1019, -67, 146, 6, 8, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_GUARD_LEFT, 1912, 1166, -67, 140, 6, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_GUARD_LEFT, 1912, 1326, -69, 97, 6, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_PUNCH_LEFT, 1912, 1445, -143, 143, 6, 9, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_KICK_LEFT, 1912, 1601, -125, 142, 6, 7, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_KICK_LEFT, 1912, 1742, -114, 101, 6, 7, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_PUNCH_LEFT, 1912, 1871, -101, 97, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_PUNCH_LEFT, 1912, 1981, -148, 88, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_JUMPED_KICK_LEFT, 1912, 2092, -129, 96, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_HIT_LEFT, 1912, 2203, -79, 136, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_LOW_HIT_LEFT, 1912, 2348, -75, 94, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_VICTORY_LEFT, 1912, 2455, -58, 167, 6, 3, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/Scorpion.png", SCORPION_CROUCHED_LEFT, 1912, 2634, -72, 86, 15, 2, true, COLLIDER_NULL),
};

AnimationData::AnimationData()
{
	this->fileName = "";
	this->animationName = 0;
	this->posX = 0;
	this->posY = 0;
	this->spriteWidth = 0;
	this->spriteHeight = 0;
	this->framerate = 0;
	this->spriteNb = 0;
	this->animationLoop = false;
	this->colliderID = COLLIDER_NULL;
}

AnimationData::AnimationData(string fileName, int animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop, int colliderID)
{
	this->fileName = fileName;
	this->animationName = animationName;
	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;
	this->animationLoop = animationLoop;
	this->colliderID = colliderID;
}

AnimationData::~AnimationData(void)
{
}

string AnimationData::getFileName() const
{
	return this->fileName;
}

int AnimationData::getAnimationName() const
{
	return this->animationName;
}

int AnimationData::getPosX() const
{
	return this->posX;
}

int AnimationData::getPosY() const
{
	return this->posY;
}

int AnimationData::getSpriteWidth() const
{
	return this->spriteWidth;
}

int AnimationData::getSpriteHeight() const
{
	return this->spriteHeight;
}

int AnimationData::getFramerate() const
{
	return this->framerate;
}

int AnimationData::getSpriteNb() const
{
	return this->spriteNb;
}

bool AnimationData::getAnimationLoop() const
{
	return this->animationLoop;
}

int AnimationData::getColliderID() const
{
	return this->colliderID;
}
