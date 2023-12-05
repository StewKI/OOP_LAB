#include <iostream>
#include "Kalkulator.h"


int main()
{
	Kalkulator k = Kalkulator("Moj kalkulator", 2020);

	k.Do(Sabiranje(5));
	k.PrikaziAcc();
	k.Do(Oduzimanje(2));
	k.PrikaziAcc();
	k.Undo();
	k.PrikaziAcc();
	k.Undo();
	k.PrikaziAcc();
}