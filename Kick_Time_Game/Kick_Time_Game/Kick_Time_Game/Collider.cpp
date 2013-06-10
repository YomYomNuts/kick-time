#include "Collider.h"
#include "GameManager.h"


Collider::Collider(void)
{
	this->colliderData = NULL;
	this->position = NULL;
	this->shiftX = 0;
	this->shiftY = 0;
	this->halfSizeX = 0;
	this->halfSizeY = 0;
}

Collider::Collider(int indexColliderData, Position * positionReference)
{
	this->colliderData = &colliderDataArray[indexColliderData];
	this->shiftX = this->colliderData->getPosX();
	this->shiftY = this->colliderData->getPosY();
	this->halfSizeX = this->colliderData->getHalfSizeX();
	this->halfSizeY = this->colliderData->getHalfSizeY();
	this->position = positionReference;
}

Collider::~Collider(void)
{
	delete this->colliderData;
	delete this->position;
}

void Collider::changeColliderData(int indexColliderData)
{
	this->colliderData = &colliderDataArray[indexColliderData];
	this->shiftX = this->colliderData->getPosX();
	this->shiftY = this->colliderData->getPosY();
	this->halfSizeX = this->colliderData->getHalfSizeX();
	this->halfSizeY = this->colliderData->getHalfSizeY();
}

const ColliderData* Collider::getColliderData()
{
	return this->colliderData;
}

Position* Collider::getPosition()
{
	return this->position;
}

void Collider::setPosition(Position * positionReference)
{
	this->position = positionReference;
}

int Collider::getShiftX()
{
	return this->shiftX;
}

void Collider::setShiftX(int shiftX)
{
	this->shiftX = shiftX;
}

int Collider::getShiftY()
{
	return this->shiftY;
}

void Collider::setShiftY(int shiftY)
{
	this->shiftY = shiftY;
}

int  Collider::getHalfSizeX()
{
	return this->halfSizeX;
}

void  Collider::setHalfSizeX(int halfSizeX)
{
	this->halfSizeX = halfSizeX;
}

int  Collider::getHalfSizeY()
{
	return this->halfSizeY;
}

void  Collider::setHalfSizeY(int halfSizeY)
{
	this->halfSizeY = halfSizeY;
}

bool Collider::AreColliding(Collider * collider) const
{
	return	abs((this->position->getX() + this->shiftX) - (collider->position->getX() + collider->getShiftX())) < this->halfSizeX + collider->getHalfSizeX() &&
			abs((this->position->getY() - this->shiftY) - (collider->position->getY() - collider->getShiftY())) < this->halfSizeY + collider->getHalfSizeY();
}

void Collider::renderCollider(const sf::Color color)
{
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(color);
	rectangle.setOutlineThickness(1);
	rectangle.setSize(sf::Vector2f((float)this->halfSizeX*2, (float)this->halfSizeY*2));
	rectangle.setPosition((float)this->position->getX() + this->shiftX - this->halfSizeX, (float)this->position->getY() - this->shiftY - this->halfSizeY);
	GameManager::getInstance()->getRenderManager()->getWindow()->draw(rectangle);
}
