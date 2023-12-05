#include "Kalkulator.h"
#pragma warning(push)
#pragma warning(disable:6385)
#pragma warning(disable:6386)

Kalkulator::Kalkulator(const char* naziv, int stackSize)
	: _maxBrOp(stackSize)
{
	int len = strlen(naziv);
	_naziv = new char[len+1];
	strcpy(_naziv, naziv);

	_akumulator = 0;

	_stekOp = new Operacija * [stackSize];
	_brOp = 0;
}

Kalkulator::Kalkulator(const Kalkulator& kalk)
	:_maxBrOp(kalk._maxBrOp)
{
	int len = strlen(kalk._naziv);
	_naziv = new char[len+1];
	strcpy(_naziv, kalk._naziv);

	_akumulator = kalk._akumulator;

	_brOp = kalk._brOp;
	_stekOp = new Operacija * [kalk._maxBrOp];

	for (int i = 0; i < _brOp; i++)
	{
		_stekOp[i] = kalk._stekOp[i]->clone();
		//*(_stekOp[i]) = *(kalk._stekOp[i]);
	}
}

Kalkulator::~Kalkulator()
{
	delete[] _naziv;
	for (int i = 0; i < _brOp; i++)
	{
		//_stekOp[i] = new Sabiranje(4);
		delete _stekOp[i];
	}
	delete[] _stekOp;
}

Kalkulator& Kalkulator::operator=(const Kalkulator& kalk)
{
	// delete old data
	delete[] _naziv;
	for (int i = 0; i < _brOp; i++)
	{
		delete _stekOp[i];
	}
	delete[] _stekOp;

	// insert new data
	int len = strlen(kalk._naziv);
	_naziv = new char[len+1];
	strcpy(_naziv, kalk._naziv);

	_akumulator = kalk._akumulator;

	_brOp = kalk._brOp;
	_stekOp = new Operacija * [kalk._maxBrOp];

	for (int i = 0; i < _brOp; i++)
	{
		_stekOp[i] = kalk._stekOp[i]->clone();
		//*(_stekOp[i]) = *(kalk._stekOp[i]);
	}

	return *this;
}

void Kalkulator::Reset()
{
	_akumulator = 0;
	for (int i = 0; i < _brOp; i++)
	{
		delete _stekOp[i];
	}
	_brOp = 0;
}

void Kalkulator::PrikaziAcc()
{
	std::cout << "Acc: " << _akumulator << std::endl;
}

bool Kalkulator::Do(const Operacija& novaOperacija)
{
	if (_brOp == _maxBrOp)
	{
		std::cerr << "No space for more operations in calculator: '" << _naziv << "'!";
		return false;
	}

	_stekOp[_brOp] = novaOperacija.clone();
	//*(_stekOp[_brOp]) = novaOperacija;
	
	_brOp++;

	_akumulator = novaOperacija.DoOperation(_akumulator, novaOperacija.VratiDrugiOperand());

	return true;
}

void Kalkulator::Undo()
{
	if (_brOp == 0) return;

	_brOp--;

	_akumulator = _stekOp[_brOp]->VratiSuprotnuOperaciju()->DoOperation(
			_akumulator, 
			_stekOp[_brOp]->VratiSuprotnuOperaciju()->VratiDrugiOperand()
	);

	delete _stekOp[_brOp];
}

#pragma warning(pop)