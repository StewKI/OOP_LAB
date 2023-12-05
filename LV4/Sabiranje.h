#pragma once
#include "Operacija.h"
class Sabiranje :
    public Operacija
{
    static int brPoOp;
public:
    Sabiranje(int drugiOperand);
    Sabiranje(const char* naziv, int drugiOperand, Operacija* suprotnaOperacija);
    Sabiranje(const Sabiranje& s);
    int DoOperation(int op1, int op2) const override;

    Operacija* clone() const override;
};

