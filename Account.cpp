
#include "Account.h"

namespace BankingSystem
{

Account::Account(double accountNum, double bal, std::string pass, Client* owner)
{
	accountNumber = accountNum;
	balance=bal;
	password=pass;
	this->owner = owner;
	owner->getMyAccounts().push_back(accountNum);
}

void Account::setBalance(double bal)
{
	balance=bal;
}
void Account::setPassword(std::string pass)
{
	password=pass;
}
void Account::setOwner(Client* owner)
{
	this->owner = owner;
}
void Account::addTransactionToHistory(double transID)
{
	this->transactions.push_back(transID);
}
double Account::getAccountNumber()
{
	return  accountNumber;
}
double Account::getBalance()
{
	return balance;
}
std::string Account::getPassword()
{
	return password;
}
Client* Account::getOwner()
{
	return owner;
}
std::vector<double> & Account::getTransactionHistory()
{
	return transactions;
}
void Account::printMyTransactionHistory(TransactionManager* manager)
{
	std::ofstream myfile ("printall.txt");
	std::vector<double>::iterator i;
	Transaction * currentTrandaction=nullptr;
		if (myfile.is_open())
		{
			for(i=transactions.end();i!=transactions.begin();i--)
			{
				currentTrandaction=(*manager).searchTransaction(*i);
				(*currentTrandaction).printTransaction(myfile);
			}	
		}
}
}