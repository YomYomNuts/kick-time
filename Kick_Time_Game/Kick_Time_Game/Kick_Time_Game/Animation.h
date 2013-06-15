#ifndef __ANIMATION__
#define __ANIMATION__


#include "LevelData.h"

#include <SFML/Graphics.hpp>

enum AnimationKind{CHARACTER, LEVEL};

class Animation
{
private:
	const LevelAnimationData * levelAnimData;
	int currentFrame;
	int frameCounter;
	bool animationDone;
	int id;

public:
	Animation(void);
	Animation(int indexAnimationData);
	~Animation(void);
	void updateAnimation();
	void renderAnimationCharacter(sf::Sprite * sprite, AnimationKind kind);
	int getCurrentFrame();
	int getId();
	int getFrameCounter();
	void setId(int id);
	void setCurrentFrame(int frame);
	void setFrameCounter(int frame);
	void resetAnimation();
	void changeAnimation(int indexAnimationData);
	const LevelAnimationData * getLevelAnimationData();
	bool getAnimationDoneState();
	void setAnimationDoneState(bool state);
};

#endif