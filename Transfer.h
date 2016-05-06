#ifndef __TRANSFER__
#define __TRANSFER__

#include<iostream>
#include<fstream>
#include<string>

#include<string>
#include "Transaction.h"
#include "AccountManager.h"
#include "Account.h"

namespace BankingSystem
{

class Transfer :public Transaction 
{
private:
	double TransferredTo;
	double amount;
	double OldBalanceTo;

public:
	Transfer(double from, double amount, double to);	
	Transfer(double id, time_t date, double balanceFrom, double balanceTo, double from, double amount, double to);	
	double getAmount();
	double getTransferredTo();
	double getOldBalanceTo();
	void modify();
	void printTransaction(std::ofstream &OutputFile);
};

}

#endif // __TRANSFER__