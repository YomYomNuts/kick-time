#include "Collider.h"


Collider::Collider(void)
{
	this->colliderData = NULL;
}

Collider::Collider(int indexColliderData)
{
	this->colliderData = &colliderDataArray[indexColliderData];
}

Collider::~Collider(void)
{
}

const ColliderData* Collider::getColliderData()
{
	return this->colliderData;
}

bool Collider::AreColliding(Collider * collider) const
{
	if (this->colliderData == NULL || collider->colliderData == NULL)
		return false;

	return	abs(this->colliderData->getPosX() - collider->colliderData->getPosX()) < this->colliderData->getHalfSizeX() + collider->colliderData->getHalfSizeX() &&
			abs(this->colliderData->getPosY() - collider->colliderData->getPosY()) < this->colliderData->getHalfSizeY() + collider->colliderData->getHalfSizeY();
}