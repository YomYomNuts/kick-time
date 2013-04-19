#include "Position.h"


Position::Position(void)
{
	this->x = 0;
	this->y = 0;
}

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

Position::~Position(void)
{
}

int Position::getX()
{
	return this->x;
}

void Position::setX(int x)
{
	this->x = x;
}

int Position::getY()
{
	return this->y;
}

int Position::setY(int y)
{
	this->y = y;
}