#include "CharacterData.h"
#include "AnimationData.h"
#include "SoundData.h"

const CharacterData characterDataArray[NUMBER_CHARACTERDATA] =
{
	CharacterData(SCORPION_STAND_RIGHT, "SCORPION", "../Ressources/Characters/MK/Scorpion/scorpionAvatar.png", 100, 3, 2, 2, 2, 2, 1, 100, 100, 100, 100, 100, 100, SOUND_SCORPION, SOUND_SCORPION, SOUND_SCORPION, SOUND_SCORPION, SOUND_SCORPION, SOUND_SCORPION),
	CharacterData(SUBZERO_STAND_RIGHT, "SUBZERO", "../Ressources/Characters/MK/Subzero/subzeroAvatar.png", 100, 3, 2, 2, 2, 2, 1, 100, 100, 100, 100, 100, 100, SOUND_SUBZERO, SOUND_SUBZERO, SOUND_SUBZERO, SOUND_SUBZERO, SOUND_SUBZERO, SOUND_SUBZERO),
};

CharacterData::CharacterData()
{
	this->animationID = 0;
	this->name = "";
	this->pathAvatar = "";
	this->totalHP = 0;
	this->damageKick = 0;
	this->damageKickCrouch = 0;
	this->damageKickJumped = 0;
	this->damagePunch = 0;
	this->damagePunchCrouch = 0;
	this->damagePunchJumped = 0;
	this->speedKick = 0;
	this->speedKickCrouch = 0;
	this->speedKickJumped = 0;
	this->speedPunch = 0;
	this->speedPunchCrouch = 0;
	this->speedPunchJumped = 0;
	this->soundKick = 0;
	this->soundPunch = 0;
	this->soundJump = 0;
	this->soundHit = 0;
	this->soundGuard = 0;
	this->soundVictory = 0;
}

CharacterData::CharacterData(int animationID, string name, string pathAvatar, int totalHP, int damageKick, int damageKickCrouch, int damageKickJumped, int damagePunch, int damagePunchCrouch, int damagePunchJumped, int speedKick, int speedKickCrouch, int speedKickJumped, int speedPunch, int speedPunchCrouch, int speedPunchJumped, int soundKick, int soundPunch, int soundJump, int soundHit, int soundGuard, int soundVictory)
{
	this->animationID = animationID;
	this->name = name;
	this->pathAvatar = pathAvatar;
	this->totalHP = totalHP;
	this->damageKick = damageKick;
	this->damageKickCrouch = damageKickCrouch;
	this->damageKickJumped = damageKickJumped;
	this->damagePunch = damagePunch;
	this->damagePunchCrouch = damagePunchCrouch;
	this->damagePunchJumped = damagePunchJumped;
	this->speedKick = speedKick;
	this->speedKickCrouch = speedKickCrouch;
	this->speedKickJumped = speedKickJumped;
	this->speedPunch = speedPunch;
	this->speedPunchCrouch = speedPunchCrouch;
	this->speedPunchJumped = speedPunchJumped;
	this->soundKick = soundKick;
	this->soundPunch = soundPunch;
	this->soundJump = soundJump;
	this->soundHit = soundHit;
	this->soundGuard = soundGuard;
	this->soundVictory = soundVictory;
}

CharacterData::~CharacterData(void)
{
}

int CharacterData::getAnimationID() const
{
	return this->animationID;
}

string CharacterData::getName() const
{
	return this->name;
}

string CharacterData::getPathAvatar() const
{
	return this->pathAvatar;
}

int CharacterData::getTotalHP() const
{
	return this->totalHP;
}

int CharacterData::getDamageKick() const
{
	return this->damageKick;
}

int CharacterData::getDamageKickCrouch() const
{
	return this->damageKickCrouch;
}

int CharacterData::getDamageKickJumped() const
{
	return this->damageKickJumped;
}

int CharacterData::getDamagePunch() const
{
	return this->damagePunch;
}

int CharacterData::getDamagePunchCrouch() const
{
	return this->damagePunchCrouch;
}

int CharacterData::getDamagePunchJumped() const
{
	return this->damagePunchJumped;
}

int CharacterData::getSpeedKick() const
{
	return this->speedKick;
}

int CharacterData::getSpeedKickCrouch() const
{
	return this->speedKickCrouch;
}

int CharacterData::getSpeedKickJumped() const
{
	return this->speedKickJumped;
}

int CharacterData::getSpeedPunch() const
{
	return this->speedPunch;
}

int CharacterData::getSpeedPunchCrouch() const
{
	return this->speedPunchCrouch;
}

int CharacterData::getSpeedPunchJumped() const
{
	return this->speedPunchJumped;
}

int CharacterData::getSoundKick() const
{
	return this->soundKick;
}

int CharacterData::getSoundPunch() const
{
	return this->soundPunch;
}

int CharacterData::getSoundJump() const
{
	return this->soundJump;
}

int CharacterData::getSoundHit() const
{
	return this->soundHit;
}

int CharacterData::getSoundGuard() const
{
	return this->soundGuard;
}

int CharacterData::getSoundVictory() const
{
	return this->soundVictory;
}
