#ifndef _COLLIDERLINE_H
#define _COLLIDERLINE_H

#include <string>

using namespace std;

class ColliderLine
{
private:
	string colliderName;
	int posX;
	int posY;
	int halfSizeX;
	int halfSizeY;
public:
	ColliderLine();
	ColliderLine(string colliderName, int posX, int posY, int halfSizeX, int halfSizeY);
	~ColliderLine(void);
	string getColliderName();
	int getPosX();
	int getPosY();
	int getHalfSizeX();
	int getHalfSizeY();
};

#endif _COLLIDERLINE_H