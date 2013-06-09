#ifndef _COLLIDER_H
#define _COLLIDER_H

#include "ColliderData.h"
#include "Position.h"

#include <SFML/Graphics.hpp>

class Collider
{
private:
	const ColliderData * colliderData;
	Position * position;
	int shiftX;
	int shiftY;
	int halfSizeX;
	int halfSizeY;

public:
	Collider(void);
	Collider(int indexColliderData, Position * positionReference);
	~Collider(void);
	void changeColliderData(int indexColliderData);
	const ColliderData* getColliderData();
	Position* getPosition();
	void setPosition(Position * positionReference);
	int getShiftX();
	void setShiftX(int shiftX);
	int getShiftY();
	void setShiftY(int shiftY);
	int getHalfSizeX();
	void setHalfSizeX(int halfSizeX);
	int getHalfSizeY();
	void setHalfSizeY(int halfSizeY);
	bool AreColliding(Collider * collider) const;
	void renderCollider(const sf::Color color);
};

#endif