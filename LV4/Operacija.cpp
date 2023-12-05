#include "Operacija.h"
#include "Sabiranje.h"

Operacija::Operacija()
{
	_naziv = nullptr;
	_drugiOperand = 0;
	_suprotnaOperacija = nullptr;
}

Operacija::Operacija(const char* naziv, int drugiOperand, Operacija* suprotnaOperacija)
{
	size_t len = strlen(naziv);
	_naziv = new char[len+1];
	strcpy(_naziv, naziv);

	_drugiOperand = drugiOperand;
	_suprotnaOperacija = suprotnaOperacija;
}

Operacija::Operacija(const Operacija& op)
{
	size_t len = strlen(op._naziv);
	_naziv = new char[len+1];
	strcpy(_naziv, op._naziv);

	_drugiOperand = op._drugiOperand;

	if (op._suprotnaOperacija != nullptr)
		_suprotnaOperacija = op._suprotnaOperacija->clone();
	else
		_suprotnaOperacija = nullptr;
}

Operacija& Operacija::operator=(const Operacija& op)
{
	size_t len = strlen(op._naziv);
	_naziv = new char[len+1];
	strcpy(_naziv, op._naziv);

	_drugiOperand = op._drugiOperand;

	if (op._suprotnaOperacija != nullptr)
		_suprotnaOperacija = op._suprotnaOperacija->clone();
	else
		_suprotnaOperacija = nullptr;

	return *this;
}

//Operacija* Operacija::operator=(const Operacija& op)
//{
//	size_t len = strlen(op._naziv);
//	_naziv = new char[len + 1];
//	strcpy(_naziv, op._naziv);
//
//	_drugiOperand = op._drugiOperand;
//
//	if (op._suprotnaOperacija != nullptr)
//		_suprotnaOperacija = op._suprotnaOperacija;
//	else
//		_suprotnaOperacija = nullptr;
//
//	return this;
//}


Operacija::~Operacija()
{
	if (_naziv != nullptr) delete[] _naziv;
	if (_suprotnaOperacija != nullptr) delete _suprotnaOperacija;
}

void Operacija::Prikazi(std::ostream& stream)
{
	stream << _naziv << " - " << _drugiOperand << " - suprotna operacija: " << _suprotnaOperacija->_naziv;
}

std::ostream& operator<<(std::ostream& stream, Operacija& op)
{
	op.Prikazi(stream);
	return stream;
}
