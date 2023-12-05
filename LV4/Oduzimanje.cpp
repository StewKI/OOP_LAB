#include "Oduzimanje.h"
#include "Sabiranje.h"
#include <string>

int Oduzimanje::brPoOp = 1;

//const char* concat(const char *s, int n) 
//{
//    int len = strlen(s);
//    char numstr[21], result = char[s+; // enough to hold all numbers up to 64-bits
//    sprintf(numstr, "%d", n);
//    return (std::string(s) + numstr).c_str();
//}

Oduzimanje::Oduzimanje(int drugiOperand)
    :Operacija("Oduzimanje", drugiOperand, new Sabiranje("suprotno od oduzimanje", drugiOperand, nullptr))
{
    brPoOp++;
}

Oduzimanje::Oduzimanje(const char* naziv, int drugiOperand, Operacija* suprotnaOperacija)
    :Operacija(naziv, drugiOperand, suprotnaOperacija)
{
}

Oduzimanje::Oduzimanje(const Oduzimanje& o)
    :Operacija(o)
{
}

int Oduzimanje::DoOperation(int op1, int op2) const
{
    return op1 - op2;
}

Operacija* Oduzimanje::clone() const
{
    return new Oduzimanje(*this);
}
