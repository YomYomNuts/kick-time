#ifndef __ANIMATIONCHARACTER__
#define __ANIMATIONCHARACTER__

#include "Animation.h"
#include "AnimationData.h"

class AnimationCharacter:public Animation
{
private:
	static int animationNumber;
	const AnimationData * animationData;
	int posX;
public:
	AnimationCharacter(void);
	AnimationCharacter(int indexAnimation);
	~AnimationCharacter(void);
	const AnimationData* getAnimationData();
	void updateAnimation();
	void renderAnimation(sf::Sprite * sprite);
	void resetAnimation();
	void changeAnimation(int indexAniamtionData);
	void setPosX(int x);
	int getPosX();
};

#endif __ANIMATIONCHARACTER__
