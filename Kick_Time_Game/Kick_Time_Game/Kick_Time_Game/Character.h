#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "Animation.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Character
{
private:
	Animation * animation;
	int posCharacterX;
	int posCharacterY;
	sf::Sprite * spriteCharacter;
	int state;
	int totalHp;
	int hp;
	void updateStand();
	void updateJump();

public:
	Character(void);
	~Character(void);
	void updateCharacter();
	void renderCharacter();
	int getTotalHp();
	int getHp();
};

#endif