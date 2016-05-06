#ifndef __DEPOSIT__
#define __DEPOSIT__

#include <iostream>
#include "Transaction.h"
#include "AccountManager.h"
#include "Account.h"

namespace BankingSystem
{

class Deposit :public Transaction 
{
private:
	double amount;

public:
	Deposit(double AccountNum, double amount);
	Deposit(double id, time_t date, double balance, double AccountNum, double amount);
	double getAmount();
	void modify();
	void printTransaction(std::ofstream &OutputFile);
}; 

}

#endif // __DEPOSIT__