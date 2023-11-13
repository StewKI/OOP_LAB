#pragma once
#include "Poligon.h"
#include <iostream>
class Slika
{
private:
	int broj_poligona, max_broj_poligona;
	Poligon* poligoni;

public:
	Slika();
	Slika(int max_broj_poligona);
	Slika(const Slika& s);
	~Slika();
	
	bool dodaj(const Poligon& p);

	friend std::ostream& operator <<(std::ostream& stream, const Slika& slika);
};

