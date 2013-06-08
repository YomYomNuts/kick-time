#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "Animation.h"
#include <SFML/Graphics.hpp>

using namespace std;

enum characterDirection{RIGHT, LEFT};

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
	characterDirection toward;

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