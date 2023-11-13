#include "Poligon.h"

#include<iostream>
#include<math.h>

Poligon::Poligon()
{
	broj_temena = 0;
	x = nullptr;
	y = nullptr;
}

Poligon::Poligon(int broj_temena)
{
	this->broj_temena = broj_temena;
	x = new int[broj_temena];
	y = new int[broj_temena];
}

Poligon::~Poligon()
{
	delete[] x;
	delete[] y;
}

double Poligon::obim()
{
	double krajnji_obim = 0.0;
	for (int i = 0; i < broj_temena; i++)
	{
		int j = (i + 1) % broj_temena;
		krajnji_obim += udaljenost(x[i], y[i], x[j], y[j]);
	}
	return krajnji_obim;
}

void Poligon::unos_temena()
{
	for (int i = 0; i < broj_temena; i++)
	{
		std::cin >> x[i] >> y[i];
	} 
}

void Poligon::najudaljenije_tacke(int* x1, int* y1, int* x2, int* y2)
{
	double max_udaljenost = -1.0;
	for (int i = 0; i < broj_temena - 1; i++) 
	{
		for (int j = i + 1; j < broj_temena; j++) 
		{
			double tren_udaljenost = udaljenost(x[i], y[i], x[j], y[j]);
			if (tren_udaljenost > max_udaljenost)
			{
				*x1 = x[i];
				*y1 = y[i];
				*x2 = x[j];
				*y2 = y[j];
				max_udaljenost = tren_udaljenost;
			}
		}
	}
}

void Poligon::prikaz_temena()
{
	std::cout << "Temena:" << std::endl;
	for (int i = 0; i < broj_temena; i++)
	{
		std::cout << x[i] << ":" << y[i] << std::endl;
	}
}

void Poligon::izbaci_jedno_teme(int n)
{
	if (n < broj_temena)
	{
		int* x_new = new int[broj_temena - 1];
		int* y_new = new int[broj_temena - 1];

		int j = 0;
		for (int i = 0; i < broj_temena; i++)
		{
			if (i != n)
			{
				x_new[j] = x[i];
				y_new[j] = y[j];
				j++;
			}
		}

		delete[] x;
		delete[] y;
		x = x_new;
		y = y_new;
		broj_temena--;
	}
}

double Poligon::udaljenost(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
