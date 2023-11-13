#pragma warning(disable:6385)

#include "Slika.h"
#include <iostream>

Slika::Slika()
{
	max_broj_poligona = 0;
	broj_poligona = 0;
	poligoni = nullptr;
}

Slika::Slika(int max_broj_poligona)
{
	this->max_broj_poligona = max_broj_poligona;
	poligoni = new Poligon[max_broj_poligona];
	broj_poligona = 0;
}

Slika::Slika(const Slika& s)
{
	max_broj_poligona = s.max_broj_poligona;
	broj_poligona = s.broj_poligona;

	if (poligoni == nullptr) delete[] poligoni;
	poligoni = new Poligon[max_broj_poligona];

	for (int i = 0; i < broj_poligona; i++)
	{
		poligoni[i] = s.poligoni[i];
	}
}

Slika::~Slika()
{
	if (poligoni != nullptr)
		delete[] poligoni;
}

bool Slika::dodaj(const Poligon& p)
{
	if (broj_poligona < max_broj_poligona)
	{
		poligoni[broj_poligona] = p;
		broj_poligona++;
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& stream, const Slika& slika)
{
	stream << "SLIKA POCETAK" << std::endl;
	for (int i = 0; i < slika.broj_poligona; i++)
	{
		stream << "-Poligon " << i+1 << ":" << std::endl;
		stream << slika.poligoni[i];
	}
	stream << "KRAJ" << std::endl;

	return stream;
}
