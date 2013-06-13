#ifndef __ANIMATION__
#define __ANIMATION__

#include "AnimationData.h"

#include <SFML/Graphics.hpp>

enum AnimationKind{CHARACTER, LEVEL};

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
	Animation(int indexAnimationData, AnimationKind kind);
	~Animation(void);
	void updateAnimation();
	void renderAnimation(sf::Sprite * sprite);
	int getPosX();
	int getCurrentFrame();
	int getId();
	void setPosX(int x);
	void setCurrentFrame(int frame);
	void resetAnimation();
	void changeAnimation(int indexAnimationData);
	const AnimationData* getAnimationData();
	bool getAnimationDoneState();
};

#endif