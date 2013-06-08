#ifndef __ANIMATION__
#define __ANIMATION__
#include "AnimationData.h"

using namespace std;

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
	int getPosY();
	int getAnimationDataWidth();
	int getAnimationDataHeight();
	int getCurrentFrame();
	int getId();
	string getAnimationDataName();
	void setPosX(int x);
	void setCurrentFrame(int frame);
	void setAnimation(AnimationData* anim);
	void resetAnimation();
	void changeAnimation(int indexAnimationData);
	const AnimationData* getAnimationData();
	bool getAnimationDoneState();
};

#endif