#pragma once
#include "Operacija.h"

class Kalkulator
{
	int _akumulator;
	char* _naziv;
	Operacija** _stekOp;
	const int _maxBrOp;
	int _brOp;

public:
	Kalkulator() = delete;
	Kalkulator(const char* naziv, int stackSize);
	Kalkulator(const Kalkulator& kalk);
	~Kalkulator();

	Kalkulator& operator =(const Kalkulator& kalk);

	void Reset();
	void PrikaziAcc();
	bool Do(const Operacija& novaOperacija);
	void Undo();
};


#include "Sabiranje.h"
#include "Oduzimanje.h"

