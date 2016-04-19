#include "Withdraw.h"
Withdraw ::Withdraw(double x )
{
	amount = x;
}

double Withdraw:: getAmount()
{
	return amount;
}
void Withdraw:: setAmount(double x)
{
	amount = x;
}

void Withdraw:: modify(double getAmount())
{
	// balance = balance - amount;
}

