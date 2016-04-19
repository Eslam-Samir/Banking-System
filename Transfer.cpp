#include "Transfer.h"
Transfer::Transfer(double x = 0)
{
	amount = x;
}

double Transfer:: getAmount()
{
	return amount;
}
void Transfer:: setAmount(double x)
{
	amount = x;
}

void Transfer::transferAmount()
{
	/*
	if (balance >= amount)
		balance = balance - amount;
		otherbalance = otherbalance + amount;
	else
		cout<<"No enough money"
	*/
	
}

void Transfer:: modify()
{
	transferAmount();
}
