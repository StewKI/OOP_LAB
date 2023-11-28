#include "PointCity.h"
#include <iostream>
#include <cstring>

PointCity::PointCity()
{
	_city = nullptr; //new char[1] {'\0'};
	_country = nullptr; //new char[1] {'\0'};
	_population = 0;
}

PointCity::PointCity(double x, double y, const char* city, const char* country, int population)
	: Point(x, y)
{
	size_t size = strlen(city);
	_city = new char[size];
	strcpy(_city, city);

	size = strlen(country);
	_country = new char[size];
	strcpy(_country, country);

	_population = population;
}

void PointCity::printData()
{
	Point::printData();
	std::cout << _city << " " << _country << "Poplation:" << _population << std::endl;
}

PointCity::~PointCity()
{
	if (_city != nullptr) delete[] _city;
	if (_country != nullptr) delete[] _country;
}

void PointCity::print_to_file(std::ostream& stream)
{
	stream << _city << "\t" << _country << "\t" << _population;
}

void PointCity::read_from_file(std::istream& stream)
{

}

