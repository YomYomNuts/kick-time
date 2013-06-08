#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "Animation.h"
#include "Collider.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Character
{
private:
	sf::Sprite * spriteCharacter;
	Animation * animation;
	Collider * collider;
	int posCharacterX;
	int posCharacterY;
	int state;
	int totalHp;
	int hp;
	void updateStand();
	void updateJump();

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
};

#endif