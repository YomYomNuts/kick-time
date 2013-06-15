#ifndef __ANIMATIONLEVEL__
#define __ANIMATIONLEVEL__

#include "Animation.h"
#include "LevelAnimationData.h"
#include "Position.h"

class AnimationLevel:public Animation
{
private:
	static int animationNumber;
	const LevelAnimationData * animationData;
	int posX;
	Position * spritePosition;
	Position * originalSpritePosition;
public:
	AnimationLevel(void);
	AnimationLevel::AnimationLevel(int levelNumber,int indexAnimation);
	~AnimationLevel(void);
	const LevelAnimationData* getAnimationData();
	void updateAnimation();
	void renderAnimation(sf::Sprite * sprite);
	void resetAnimation();
	void setPosX(int x);
	int getPosX();
	double getPosXSprite();
	double getPosYSprite();
	void setPosXSprite(double x);
	void setPosYSprite(double y);
	double getPosXOriginalSpritePosition();
	double getPosYOriginalSpritePosition();
};

#endif __ANIMATIONLEVEL__

