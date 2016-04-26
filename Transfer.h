#ifndef __TRANSFER__
#define __TRANSFER__

#include <iostream>
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

public:
	Transfer(double from, double amount, double to);	
	double getAmount();
	double getTransferredTo();
	void modify();
};

}

#endif // __TRANSFER__