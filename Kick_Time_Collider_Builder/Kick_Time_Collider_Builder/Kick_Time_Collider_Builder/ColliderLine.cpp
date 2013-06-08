#include "ColliderLine.h"

ColliderLine::ColliderLine()
{
	this->colliderName = "";
	this->posX = 0;
	this->posY = 0;
	this->halfSizeX = 0;
	this->halfSizeY = 0;
}

ColliderLine::ColliderLine(string colliderName, int posX, int posY, int halfSizeX, int halfSizeY)
{
	this->colliderName = colliderName;
	this->posX = posX;
	this->posY = posY;
	this->halfSizeX = halfSizeX;
	this->halfSizeY = halfSizeY;
}

ColliderLine::~ColliderLine(void)
{
}

string ColliderLine::getColliderName()
{
	return this->colliderName;
}

int ColliderLine::getPosX()
{
	return this->posX;
}

int ColliderLine::getPosY()
{
	return this->posY;
}

int ColliderLine::getHalfSizeX()
{
	return this->halfSizeX;
}

int ColliderLine::getHalfSizeY()
{
	return this->halfSizeY;
}