#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "AnimationCharacter.h"
#include "Collider.h"
#include "Position.h"
#include "CharacterData.h"

#include <SFML/Graphics.hpp>

using namespace std;

// Direction character
enum CharacterDirection {
	CHARACTER_DIRECTION_RIGHT,
	CHARACTER_DIRECTION_LEFT
};

// State character
enum CharacterState {
	STATE_CHARACTER_STAND,
	STATE_CHARACTER_MOVE_RIGHT,
	STATE_CHARACTER_MOVE_LEFT,
	STATE_CHARACTER_CROUCH,
	STATE_CHARACTER_STANDUP,
	STATE_CHARACTER_STEADY_JUMP_UP,
	STATE_CHARACTER_STEADY_JUMP_DOWN,
	STATE_CHARACTER_FORWARD_JUMP,
	STATE_CHARACTER_BACKWARD_JUMP,
	STATE_CHARACTER_GUARD,
	STATE_CHARACTER_GUARD_ON,
	STATE_CHARACTER_LOW_GUARD,
	STATE_CHARACTER_LOW_GUARD_ON,
	STATE_CHARACTER_PUNCH,
	STATE_CHARACTER_KICK,
	STATE_CHARACTER_CROUCHED_KICK,
	STATE_CHARACTER_CROUCHED_PUNCH,
	STATE_CHARACTER_JUMPED_PUNCH,
	STATE_CHARACTER_JUMPED_KICK,
	STATE_CHARACTER_HIT,
	STATE_CHARACTER_LOW_HIT,
	STATE_CHARACTER_VICTORY,
	STATE_CHARACTER_CROUCHED,
	NUMBER_STATE_CHARACTER
};

class Character
{
private:
	sf::Sprite * spriteCharacter;
	AnimationCharacter * animation;
	Collider * collider;
	Position * positionCharacter;
	CharacterDirection toward;
	CharacterState state;
	Collider * colliderKickPunch;
	const CharacterData * characterData;
	int indexCharacter;
	int totalHp;
	int hp;
	bool endOfScreenReached;
	int numberRoundWin;
	bool completelyDead;
	void updateStand();
	void updateMoveRight();
	void updateMoveLeft();
	void updateCrouch();
	void updateStandUp();
	void updateSteadyJumpUp();
	void updateSteadyJumpDown();
	void updateForwardJump();
	void updateBackwardJump();
	void updateGuard();
	void updateGuardOn();
	void updateLowGuard();
	void updateLowGuardOn();
	void updatePunch();
	void updateKick();
	void updateCrouchedKick();
	void updateCrouchedPunch();
	void updateJumpedPunch();
	void updateJumpedKick();
	void updateHit();
	void updateLowHit();
	void updateVictory();
	void updateCrouched();
	void checkDirection();
	void updateKickPunch(int damage, int speed);

public:
	Character(void);
	Character(int indexCharacter, int indexTypeCharacter);
	~Character(void);
	AnimationCharacter* getAnimation();
	void updateCharacter();
	void renderCharacter();
	void setPosCharacterX(double posX);
	void setPosCharacterY(double posY);
	double getPosCharacterX();
	double getPosCharacterY();
	int getTotalHp();
	int getHp();
	int getIndexCharacter();
	Collider* getCollider();
	void moveRight(double speedCoef);
	void moveLeft(double speedCoef);
	void moveUp(double speedCoef);
	void moveDown(double speedCoef);
	void updateAnimationCharacter();
	void hitCharacter(int damage);
	bool getEndOfScreenReachedState();
	CharacterState getCharacterState();
	const CharacterData* getCharacterData();
	void setNumberRoundWin(int numberRoundWin);
	int getNumberRoundWin();
	void restoreHp(int hp);
	void resetInformations();
};

#endif
