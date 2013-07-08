#ifndef _CHARACTERDATA_H
#define _CHARACTERDATA_H

#include <string>

using namespace std;

class CharacterData
{
private:
	int animationID;
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
	int soundKick;
	int soundPunch;
	int soundJump;
	int soundHit;
	int soundGuard;
	int soundVictory;

public:
	CharacterData();
	CharacterData(int animationID, string name, string pathAvatar, int totalHP, int damageKick, int damageKickCrouch, int damageKickJumped, int damagePunch, int damagePunchCrouch, int damagePunchJumped, int speedKick, int speedKickCrouch, int speedKickJumped, int speedPunch, int speedPunchCrouch, int speedPunchJumped, int soundKick, int soundPunch, int soundJump, int soundHit, int soundGuard, int soundVictory);
	~CharacterData(void);
	int getAnimationID() const;
	string getName() const;
	string getPathAvatar() const;
	int getTotalHP() const;
	int getDamageKick() const;
	int getDamageKickCrouch() const;
	int getDamageKickJumped() const;
	int getDamagePunch() const;
	int getDamagePunchCrouch() const;
	int getDamagePunchJumped() const;
	int getSpeedKick() const;
	int getSpeedKickCrouch() const;
	int getSpeedKickJumped() const;
	int getSpeedPunch() const;
	int getSpeedPunchCrouch() const;
	int getSpeedPunchJumped() const;
	int getSoundKick() const;
	int getSoundPunch() const;
	int getSoundJump() const;
	int getSoundHit() const;
	int getSoundGuard() const;
	int getSoundVictory() const;
};

#define NUMBER_CHARACTERDATA 2

extern const CharacterData characterDataArray[NUMBER_CHARACTERDATA];

#define SCORPION 0
#define SUBZERO 1

#endif _CHARACTERDATA_H
