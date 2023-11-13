#include "Poligon.h"

#include<iostream>
#include<math.h>
#include<memory>

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

Poligon::Poligon(const Poligon& p)
{
	broj_temena = p.broj_temena;
	x = new int[broj_temena];
	y = new int[broj_temena];
	std::copy(p.x, p.x + p.broj_temena, x);
	std::copy(p.y, p.y + p.broj_temena, y);
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

void Poligon::preslikaj_x_osa()
{
	for (int i = 0; i < broj_temena; i++)
	{
		y[i] = -(y[i]);
	}
}

void Poligon::preslikaj_y_osa()
{
	for (int i = 0; i < broj_temena; i++)
	{
		x[i] = -(x[i]);
	}
}

Poligon& Poligon::operator=(const Poligon& p)
{
	if (x != nullptr) delete[] x;
	if (y != nullptr) delete[] y;

	broj_temena = p.broj_temena;
	x = new int[broj_temena];
	y = new int[broj_temena];
	std::copy(p.x, p.x + p.broj_temena, x);
	std::copy(p.y, p.y + p.broj_temena, y);

	return *this;
}

double Poligon::udaljenost(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

std::istream& operator>>(std::istream& stream, const Poligon& poligon)
{
	for (int i = 0; i < poligon.broj_temena; i++)
	{
		stream >> poligon.x[i] >> poligon.y[i];
	} 
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Poligon& poligon)
{
	for (int i = 0; i < poligon.broj_temena; i++)
	{
		stream << poligon.x[i] << ":" << poligon.y[i] << std::endl;
	}
	return stream;
}
