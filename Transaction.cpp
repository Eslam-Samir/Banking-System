#include "Transaction.h"

namespace BankingSystem
{

Transaction::Transaction(double number, TransactionType type) 
{
	double transNum = 0;
	for (int i = 0; i < 3; i++)
	{
		transNum += rand() % 10;
		transNum *= 10;
	}
	transNum += rand() % 10;
	this->TransactionId = transNum;
	this->AccountNumber = number;
	this->Type = type;
}
Transaction::Transaction(double id, double number, TransactionType type) 
{
	this->TransactionId = id;
	this->AccountNumber = number;
	this->Type = type;
}
//getters
TransactionType Transaction::getType()
{
	return Type;
}
 double Transaction::getTransactionId()
{
	return TransactionId;
}
double Transaction::getAccountNumber()
{
	return AccountNumber;
}

}