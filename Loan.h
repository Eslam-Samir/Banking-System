#ifndef __LOAN__
#define __LOAN__

#include <iostream>
#include "Transaction.h"
#include "AccountManager.h"
#include "Account.h"

namespace BankingSystem
{

class Loan :public Transaction 
{
private:
	double amount;

public:
	Loan(double AccountNum, double amount);	
	Loan(double id, time_t date, double balance, double AccountNum, double amount);	
	double getAmount();	
	void modify();
	void printTransaction(std::ofstream &OutputFile);
}; 

}

#endif // __LOAN__