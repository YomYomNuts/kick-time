#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Animation.h"
#include "Collider.h"

#include <SFML/Graphics.hpp>

using namespace std;

// Direction character
enum CharacterDirection {
	RIGHT,
	LEFT
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
	STATE_CHARACTER_GUARD,
	STATE_CHARACTER_LOW_GUARD,
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
	Animation * animation;
	Collider * collider;
	CharacterDirection toward;
	CharacterState state;
	int posCharacterX;
	int posCharacterY;
	int indexCharacter;
	int totalHp;
	int hp;
	void updateStand();
	void updateMoveRight();
	void updateMoveLeft();
	void updateCrouch();
	void updateStandUp();
	void updateSteadyJumpUp();
	void updateSteadyJumpDown();
	void updateForwardJump();
	void updateGuard();
	void updateLowGuard();
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

public:
	Character(void);
	Character(int indexCharacter);
	~Character(void);
	Animation* getAnimation();
	void updateCharacter();
	void renderCharacter();
	void setPosCharacterX(int posX);
	void setPosCharacterY(int posY);
	int getPosCharacterX();
	int getPosCharacterY();
	int getTotalHp();
	int getHp();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void updateAnimationCharacter();
};

#endif