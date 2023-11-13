#include "Poligon.h"
#include "Slika.h"
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	Poligon* p1 = new Poligon(n);
	std::cin >> *p1;
	p1->preslikaj_x_osa();
	std::cout << "Preslikavanje po x:" << std::endl << *p1;
	p1->preslikaj_y_osa();
	std::cout << "Preslikavanje po x pa po y:" << std::endl << *p1;

	int m;
	std::cin >> m;
	Poligon* p2 = new Poligon(m);
	std::cin >> *p2;
	p2->preslikaj_x_osa();
	std::cout << "Preslikavanje po x:" << std::endl << *p2;
	p2->preslikaj_y_osa();
	std::cout << "Preslikavanje po x pa po y:" << std::endl << *p2;

	int k;
	std::cin >> k;
	Slika slika(k);
	slika.dodaj(*p1);
	slika.dodaj(*p2);
	for (int i = 2; i < k; i++)
	{
		int np;
		std::cin >> np;
		Poligon p(np);
		std::cin >> p;
		slika.dodaj(p);
	}
	std::cout << slika;

}