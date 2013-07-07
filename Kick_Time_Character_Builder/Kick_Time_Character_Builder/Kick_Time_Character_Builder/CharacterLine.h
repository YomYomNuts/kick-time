#ifndef _CHARACTERLINE_H
#define _CHARACTERLINE_H

#include <string>

using namespace std;

class CharacterLine
{
private:
	string animationName;
	string name;
	string pathAvatar;
	int totalHP;
	int damageKick;
	int damageKickCrouch;
	int damageKickJumped;
	int damagePunch;
	int damagePunchCrouch;
	int damagePunchJumped;
	int speedKick;
	int speedKickCrouch;
	int speedKickJumped;
	int speedPunch;
	int speedPunchCrouch;
	int speedPunchJumped;
	string soundKick;
	string soundPunch;
	string soundJump;
	string soundHit;
	string soundGuard;
	string soundVictory;
public:
	CharacterLine();
	CharacterLine(string animationName, string name, string pathAvatar, int totalHP, int damageKick, int damageKickCrouch, int damageKickJumped, int damagePunch, int damagePunchCrouch, int damagePunchJumped, int speedKick, int speedKickCrouch, int speedKickJumped, int speedPunch, int speedPunchCrouch, int speedPunchJumped, string soundKick, string soundPunch, string soundJump, string soundHit, string soundGuard, string soundVictory);
	~CharacterLine(void);
	string getAnimationName();
	string getName();
	string getPathAvatar();
	int getTotalHP();
	int getDamageKick();
	int getDamageKickCrouch();
	int getDamageKickJumped();
	int getDamagePunch();
	int getDamagePunchCrouch();
	int getDamagePunchJumped();
	int getSpeedKick();
	int getSpeedKickCrouch();
	int getSpeedKickJumped();
	int getSpeedPunch();
	int getSpeedPunchCrouch();
	int getSpeedPunchJumped();
	string getSoundKick();
	string getSoundPunch();
	string getSoundJump();
	string getSoundHit();
	string getSoundGuard();
	string getSoundVictory();
};

#endif _CHARACTERLINE_H