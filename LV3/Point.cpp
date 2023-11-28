#include "Point.h"
#include <iostream>
#include <math.h>

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(double x, double y)
{
	_x = x;
	_y = y;
}

double Point::distance(const Point& from)
{
	double x_dis = _x - from._x;
	double y_dis = _y - from._y;
	return sqrt(x_dis * x_dis + y_dis * y_dis);
}

Point::~Point()
{
}

void Point::printData()
{
	std::cout << std::endl;
	std::cout << "X:" << _x << " Y:" << _y << std::endl;
}
