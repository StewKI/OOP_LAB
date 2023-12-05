#include "Sabiranje.h"
#include "Oduzimanje.h"

int Sabiranje::brPoOp = 1;


Sabiranje::Sabiranje(int drugiOperand)
    :Operacija("Sabiranje", drugiOperand, new Oduzimanje("suprotno od sabiranje", drugiOperand, nullptr))
{
    brPoOp++;
}

Sabiranje::Sabiranje(const char* naziv, int drugiOperand, Operacija* suprotnaOperacija)
    :Operacija(naziv, drugiOperand, suprotnaOperacija)
{
}

Sabiranje::Sabiranje(const Sabiranje& s)
    :Operacija(s)
{
}

int Sabiranje::DoOperation(int op1, int op2) const
{
    return op1 + op2;
}

Operacija* Sabiranje::clone() const
{
    return new Sabiranje(*this);
}
