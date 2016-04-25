#include "Transaction.h"

//Transaction::Transaction()
//{}

Transaction::Transaction(double id = 0, double number = 0) {
	TransactionId = id;
	AccountNumber = number;
}

//setters and getters
 double Transaction::getTransactionId()
{
	return TransactionId;
}
void Transaction::setTransactionId(double x)
{
	TransactionId = x;
}

double Transaction::getAccountNumber()
{
	return AccountNumber;
}
void Transaction::setTAccountNumber(double x)
{
	AccountNumber = x;
}

 void Transaction::modify()
{
	
}
