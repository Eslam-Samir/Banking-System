#include "Account.h"

Account::Account(double bal, std::string pass, Client & owner)
{
	accountNumber = AccountManager::getAccountManager()->getNumberOfAccounts();
	balance=bal;
	password=pass;
	this->owner = owner;
}
void Account::setBalance(double bal)
{
	balance=bal;
}
void Account::setPassword(std::string pass)
{
	password=pass;
}
void Account::setOwner(Client owner)
{
	this->owner = owner;
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
Client & Account::getOwner()
{
	return owner;
}