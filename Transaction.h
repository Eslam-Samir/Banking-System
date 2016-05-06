#ifndef __TRANSACTION__
#define __TRANSACTION__

#include <iostream>
#include <ctime>
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
	double OldBalance;
	TransactionType Type;
	time_t Date; 

protected:
	void setOldBalance(double balance);

public:
	//constructor
	Transaction(double number, TransactionType type);
	Transaction(double id, time_t date, double balance, double number, TransactionType type);

	//getters
	TransactionType getType();
	double getTransactionId();	
	double getAccountNumber();	
	double getOldBalance();
	time_t getDate();
	//std::string getFormatedDate();

	// virtual functions for polymorphism
	virtual void modify() = 0;
	virtual void printTransaction(std::ifstream &OutputFile);

};

}

#endif // __TRANSACTION__