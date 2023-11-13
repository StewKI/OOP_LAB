#pragma once

class Poligon
{
private:
	int broj_temena;
	int* x, * y;

public:
	Poligon();
	Poligon(int broj_temena);
	~Poligon();
	inline int get_broj_temena() { return broj_temena; }
	double obim();
	void unos_temena();
	void najudaljenije_tacke(int* x1, int* y1, int* x2, int* y2);
	void prikaz_temena();
	void izbaci_jedno_teme(int n);

private:
	double udaljenost(int x1, int y1, int x2, int y2);
};

