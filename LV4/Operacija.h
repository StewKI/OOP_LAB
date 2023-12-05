#pragma once
#include<iostream>

class Operacija
{
	char* _naziv;
	int _drugiOperand;
	Operacija* _suprotnaOperacija;

public:
	Operacija();
	Operacija(const char* naziv, int drugiOperand, Operacija* suprotnaOperacija);
	Operacija(const Operacija& op);
	Operacija& operator =(const Operacija& op);
	virtual Operacija* clone() const = 0;
	virtual ~Operacija();

	inline Operacija* VratiSuprotnuOperaciju() { return _suprotnaOperacija; }
	inline int VratiDrugiOperand() const { return _drugiOperand; }
	void Prikazi(std::ostream& stream);

	virtual int DoOperation(int op1, int op2) const = 0;

	friend std::ostream& operator <<(std::ostream& stream, const Operacija& op);
};

