#pragma once
#include "Operacija.h"
class Oduzimanje :
    public Operacija
{
    static int brPoOp;
public:
    Oduzimanje(int drugiOperand);
    Oduzimanje(const char* naziv, int drugiOperand, Operacija* suprotnaOperacija);
    Oduzimanje(const Oduzimanje& o);
    int DoOperation(int op1, int op2) const override;

    Operacija* clone() const override;
};

