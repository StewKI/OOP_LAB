#pragma once
#include <iostream>

class Poligon
{
private:
	int broj_temena;
	int* x, * y;

public:
	Poligon();
	Poligon(int broj_temena);
	Poligon(const Poligon& p);
	~Poligon();

	inline int get_broj_temena() { return broj_temena; }
	double obim();
	void najudaljenije_tacke(int* x1, int* y1, int* x2, int* y2);
	void izbaci_jedno_teme(int n);

	void preslikaj_x_osa();
	void preslikaj_y_osa();

	friend std::istream& operator >>(std::istream& stream, const Poligon& poligon);
	friend std::ostream& operator <<(std::ostream& stream, const Poligon& poligon);

	Poligon& operator =(const Poligon& p);


private:
	double udaljenost(int x1, int y1, int x2, int y2);
};

