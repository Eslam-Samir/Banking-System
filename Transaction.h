#ifndef __TRANSACTION__
#define __TRANSACTION__

#include <iostream>
#include "AccountManager.h"

namespace BankingSystem
{

enum TransactionType {
	withdraw = 0,
	deposit = 1,
	transfer = 2,
	loan = 3,
	query = 4
};

class Transaction 
{
private:
	double TransactionId;
	double AccountNumber;
	TransactionType Type;
	//date TODO

public:
	//constructor
	Transaction(double number, TransactionType type);
	Transaction(double id, double number, TransactionType type);

	//getters
	TransactionType getType();
	double getTransactionId();	
	double getAccountNumber();	
	virtual void modify() = 0;
	

};

}

#endif // __TRANSACTION__