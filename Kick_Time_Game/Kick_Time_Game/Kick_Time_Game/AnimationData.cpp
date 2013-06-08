#include "AnimationData.h"
#include "ColliderData.h"

const AnimationData animationDataArray[NUMBER_ANIMATIONDATA] =
{
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_STAND_RIGHT, 0, 0, 76, 134, 9, 7, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_VICTORY, 0, 134, 70, 157, 9, 4, false, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_FORWARD_RIGHT, 0, 291, 87, 136, 8, 9, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_BACKWARD_RIGHT, 0, 427, 87, 135, 8, 9, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_STOOP_RIGHT, 0, 562, 71, 120, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_PICKUP_RIGHT, 0, 682, 71, 120, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_JUMPUP_RIGHT, 0, 802, 71, 144, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_JUMP_RIGHT, 0, 946, 77, 136, 8, 8, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_PUNCHRIGHT_RIGHT, 0, 1082, 118, 138, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_PUNCHLEFT_RIGHT, 0, 1220, 118, 138, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_KICKRIGHT_RIGHT, 0, 1358, 137, 137, 8, 8, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_KICKLEFT_RIGHT, 0, 1495, 143, 137, 8, 7, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_KICKJUMP_RIGHT, 0, 1632, 134, 99, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_KICKDOWN_RIGHT, 0, 1731, 112, 94, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_BLOCKING_RIGHT, 0, 1825, 71, 136, 8, 3, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_BLOCKINGDOWN_RIGHT, 0, 1961, 63, 97, 8, 2, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_HIT_RIGHT, 0, 2058, 84, 144, 8, 6, true, COLLIDER_NULL),
	AnimationData("../Ressources/Characters/MK/Scorpion/scorpion.png", SCORPION_HITDOWN_RIGHT, 0, 2202, 87, 81, 8, 3, true, COLLIDER_NULL),
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
