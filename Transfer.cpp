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

void Transfer:: modify(double getAmount())
{
	// balance = balance - amount;

	//other client balance = balance+amount;

}
