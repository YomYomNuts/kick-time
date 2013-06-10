#ifndef _POSITION_H
#define _POSITION_H



class Position
{
private:
	double x;
	double y;

public:
	Position(void);
	Position(double x, double y);
	~Position(void);
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);
};

#endif