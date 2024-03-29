#ifndef __WITHDRAW__
#define __WITHDRAW__

#include <iostream>
#include "Transaction.h"
#include "AccountManager.h"
#include "Account.h"

namespace BankingSystem
{

class Withdraw :public Transaction 
{
private:
	double amount;

public:
	Withdraw(double AccountNum, double amount);
	Withdraw(double id, time_t date, double balance, double AccountNum, double amount);
	double getAmount();
	void modify();
	void printTransaction(std::ofstream &OutputFile);
};

}

#endif // __WITHDRAW__