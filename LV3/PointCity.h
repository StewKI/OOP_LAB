#pragma once
#include "Point.h"

class PointCity : public Point
{
	char* _city, * _country;
	int _population;

public:
	PointCity();
	PointCity(double x, double y, const char* city, const char* country, int population);
	void printData();
	~PointCity();

	void print_to_file(std::ostream& stream);
	void read_from_file(std::istream& stream);
};

