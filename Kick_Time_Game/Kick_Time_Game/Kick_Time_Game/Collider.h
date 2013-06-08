#ifndef _COLLIDER_H
#define _COLLIDER_H

#include "ColliderData.h"

class Collider
{
private:
	const ColliderData * colliderData;

public:
	Collider(void);
	Collider(int indexColliderData);
	~Collider(void);
	const ColliderData* getColliderData();
	bool AreColliding(Collider * colliderData) const;
};

#endif