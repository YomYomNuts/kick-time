#ifndef _POSITION_H
#define _POSITION_H

class Position
{
private:
	int x;
	int y;
public:
	Position(void);
	Position(int x, int y);
	~Position(void);
	int getX();
	void setX(int x);
	int getY();
	int setY(int y);
};

#endif