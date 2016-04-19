#include"Loan.h"



Loan::Loan(double x = 0)
{
	amount = x;
}

double Loan:: getAmount()
{
	return amount;
}
void Loan:: setAmount(double x)
{
	amount = x;
}


void Loan::loanAmount(bool t)
{
	 /*/
	 if (t==true)
		balance = balance + amount;
	
	/*/
}

void Loan::modify()
{
	loanAmount();
}
