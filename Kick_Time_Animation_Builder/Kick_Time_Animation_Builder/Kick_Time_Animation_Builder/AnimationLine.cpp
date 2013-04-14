#include "AnimationLine.h"

AnimationLine::AnimationLine(char* fileName, char* animationName, int posX, int posY, int spriteWidth, int spriteHeight, int framerate, int spriteNb, bool animationLoop){

	this->fileName = new char[strlen(fileName)+1];
	strcpy_s(this->fileName,strlen(fileName)+1, fileName);

	this->animationName = new char[strlen(animationName)+1];
	strcpy_s(this->animationName,strlen(animationName)+1, animationName);

	this->posX = posX;
	this->posY = posY;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->framerate = framerate;
	this->spriteNb = spriteNb;
	this->animationLoop = animationLoop;
}

char* AnimationLine::getFileName(){
	return fileName;
}

char* AnimationLine::getAnimationName(){
	return animationName;
}

int AnimationLine::getPosX(){
	return posX;
}

int AnimationLine::getPosY(){
	return posY;
}

int AnimationLine::getSpriteWidth(){
	return spriteWidth;
}

int AnimationLine::getSpriteHeight(){
	return spriteHeight;
}

int AnimationLine::getFramerate(){
	return framerate;
}

int AnimationLine::getSpriteNb(){
	return spriteNb;
}

bool AnimationLine::getAnimationLoop(){
	return animationLoop;
}