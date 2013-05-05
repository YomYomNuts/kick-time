#ifndef _ANIMATIONMANAGER_H
#define _ANIMATIONMANAGER_H
#include <vector>
#include "Animation.h"

using namespace std;

class AnimationManager
{
private:
	vector<Animation*> * animationList;

public:
	AnimationManager(void);
	~AnimationManager(void);
	void initializeAnimationManager();
	void updateAnimationManager();
	void addAnimation(Animation * anim);
	void removeAnimation(Animation * anim);
};

#endif