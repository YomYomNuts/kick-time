#ifndef _ANIMATIONMANAGER_H
#define _ANIMATIONMANAGER_H

#include "AnimationCharacter.h"
#include "AnimationLevel.h"

#include <vector>

using namespace std;

class AnimationManager
{
private:
	vector<AnimationCharacter*> * animationCharacterList;
	vector<AnimationLevel*> * animationLevelList;
public:
	AnimationManager(void);
	~AnimationManager(void);
	void initializeAnimationManager();
	void updateAnimationManager();
	void addCharacterAnimation(AnimationCharacter * anim);
	void removeCharacterAnimation(AnimationCharacter * anim);
	void addLevelAnimation(AnimationLevel * anim);
	void removeLevelAnimation(AnimationLevel * anim);
};

#endif