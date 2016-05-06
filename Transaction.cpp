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

	Date = time(0);

	this->TransactionId = transNum;
	this->AccountNumber = number;
	this->Type = type;
}
Transaction::Transaction(double id, time_t date, double balance, double number, TransactionType type) 
{
	this->TransactionId = id;
	this->AccountNumber = number;
	this->Type = type;
	this->OldBalance = balance;
	this->Date = date;
}

void Transaction::setOldBalance(double balance)
{
	this->OldBalance = balance;
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
double Transaction::getOldBalance()
{
	return OldBalance;
}
time_t Transaction::getDate()
{
	return Date;
}
/*std::string Transaction::getFormatedDate()
{
	char* s=new char[26];
	ctime_s(s,26,&Date);
	return s;
}*/

}