#include "CharacterLine.h"

CharacterLine::CharacterLine()
{
	this->animationName = "";
	this->name = "";
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
	this->soundKick = "";
	this->soundPunch = "";
	this->soundJump = "";
	this->soundHit = "";
	this->soundGuard = "";
	this->soundVictory = "";
}

CharacterLine::CharacterLine(string animationName, string name, int totalHP, int damageKick, int damageKickCrouch, int damageKickJumped, int damagePunch, int damagePunchCrouch, int damagePunchJumped, int speedKick, int speedKickCrouch, int speedKickJumped, int speedPunch, int speedPunchCrouch, int speedPunchJumped, string soundKick, string soundPunch, string soundJump, string soundHit, string soundGuard, string soundVictory)
{
	this->animationName = animationName;
	this->name = name;
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

CharacterLine::~CharacterLine(void)
{
}

string CharacterLine::getAnimationName()
{
	return this->animationName;
}

string CharacterLine::getName()
{
	return this->name;
}

int CharacterLine::getTotalHP()
{
	return this->totalHP;
}

int CharacterLine::getDamageKick()
{
	return this->damageKick;
}

int CharacterLine::getDamageKickCrouch()
{
	return this->damageKickCrouch;
}

int CharacterLine::getDamageKickJumped()
{
	return this->damageKickJumped;
}

int CharacterLine::getDamagePunch()
{
	return this->damagePunch;
}

int CharacterLine::getDamagePunchCrouch()
{
	return this->damagePunchCrouch;
}

int CharacterLine::getDamagePunchJumped()
{
	return this->damagePunchJumped;
}

int CharacterLine::getSpeedKick()
{
	return this->speedKick;
}

int CharacterLine::getSpeedKickCrouch()
{
	return this->speedKickCrouch;
}

int CharacterLine::getSpeedKickJumped()
{
	return this->speedKickJumped;
}

int CharacterLine::getSpeedPunch()
{
	return this->speedPunch;
}

int CharacterLine::getSpeedPunchCrouch()
{
	return this->speedPunchCrouch;
}

int CharacterLine::getSpeedPunchJumped()
{
	return this->speedPunchJumped;
}

string CharacterLine::getSoundKick()
{
	return this->soundKick;
}

string CharacterLine::getSoundPunch()
{
	return this->soundPunch;
}

string CharacterLine::getSoundJump()
{
	return this->soundJump;
}

string CharacterLine::getSoundHit()
{
	return this->soundHit;
}

string CharacterLine::getSoundGuard()
{
	return this->soundGuard;
}

string CharacterLine::getSoundVictory()
{
	return this->soundVictory;
}