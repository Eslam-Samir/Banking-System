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
void Withdraw::withdrawAmount()
{
	/*
	if(balance>=amount)
		balance = balance-amount;
		cout<<"balance;
	else 
		cout<< "No enough money"
	*/
}

void Withdraw:: modify()
{
	withdrawAmount();
}

