#include "Position.h"


Position::Position(void)
{
	this->x = 0;
	this->y = 0;
}

Position::Position(double x, double y)
{
	this->x = x;
	this->y = y;
}

Position::~Position(void)
{
}

double Position::getX() const
{
	return this->x;
}

void Position::setX(double x)
{
	this->x = x;
}

double Position::getY() const
{
	return this->y;
}

void Position::setY(double y)
{
	this->y = y;
}