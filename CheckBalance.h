#ifndef __CHECKBALANCE__
#define __CHECKBALANCE__

#include "Transaction.h"
#include "AccountManager.h"
#include <iostream>

namespace BankingSystem
{

class CheckBalance :public Transaction 
{
public:
	CheckBalance(double AccountNum);
	CheckBalance(double id, time_t date, double balance, double AccountNum);
	void modify();

};

}

#endif // __CHECKBALANCE__