#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Animation.h"
#include "Collider.h"

#include <SFML/Graphics.hpp>

using namespace std;

enum CharacterDirection {
	RIGHT,
	LEFT
};

class Character
{
private:
	sf::Sprite * spriteCharacter;
	Animation * animation;
	Collider * collider;
	int posCharacterX;
	int posCharacterY;
	int state;
	CharacterDirection toward;
	int totalHp;
	int hp;
	void updateStand();
	void updateForward();
	void updateBackward();
	void updateCrouch();
	void updateStandUp();
	void updateSteadyJump();
	void updateForwardJump();
	void updateGuard();
	void updateLowGuard();
	void updatePunch();
	void updateKick();
	void updateCrouchedKick();
	void updateJumpedPunch();
	void updateJumpedKick();
	void updateHit();
	void updateLowHit();
	void updateVictory();

public:
	Character(void);
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
	void moveForward();
	void moveBackward();
};

#endif