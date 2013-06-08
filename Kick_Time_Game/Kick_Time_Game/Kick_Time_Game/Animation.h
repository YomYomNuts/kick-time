#ifndef __ANIMATION__
#define __ANIMATION__

#include "AnimationData.h"

class Animation
{
private:
	const AnimationData * animationData;
	int posX;
	int currentFrame;
	int frameCounter;
	bool animationDone;
	static int animationNumber;
	int id;

public:
	Animation(void);
	Animation(int indexAnimationData);
	~Animation(void);
	void update();
	int getPosX();
	int getCurrentFrame();
	int getId();
	void setPosX(int x);
	void setCurrentFrame(int frame);
	void resetAnimation();
	void changeAnimation(int indexAnimationData);
	const AnimationData* getAnimationData();
};

#endif