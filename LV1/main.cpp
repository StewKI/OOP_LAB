#include "Poligon.h"
#include <iostream>

int main()
{
	Poligon p1(3);
	p1.unos_temena();
	std::cout << p1.obim() << std::endl;
	
	Poligon* p2 = new Poligon(3);

	p2->unos_temena();
	std::cout << "Broj temena: " << p2->get_broj_temena() << std::endl;
	int x1, y1, x2, y2;
	p2->najudaljenije_tacke(&x1, &y1, &x2, &y2);
	std::cout << "Najudaljenjije tacke:" << std::endl
		      << x1 << ":" << y1 << std::endl
		      << x2 << ":" << y2 << std::endl;
	p2->izbaci_jedno_teme(1);
	p2->prikaz_temena();

}