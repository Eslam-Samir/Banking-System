#include "Deposit.h"


Deposit::Deposit(double x)
{
	amount = x;
}

double Deposit::getAmount()
{
	return amount;
}
void Deposit::setAmount(double x)
{
	amount = x;
}

void Deposit::modify(double getAmount())
{
	// balance = balance + amount;
}
