#pragma once
#include <iostream>
class Point
{
protected:
	double _x, _y;

public:
	Point();
	Point(double x, double y);
	double distance(const Point& from);
	virtual ~Point();
	virtual void printData();
};

