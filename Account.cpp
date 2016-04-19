#include "Account.h"
double Account:: numberOfAccounts=0;
Account::Account()
{}
	
Account::Account(double acntnumber,double bal,std::string pass)
{
	numberOfAccounts++;
	accountNumber=acntnumber;
	balance=bal;
	password=pass;
	accountNumber=numberOfAccounts;
}
void Account::setBalance(double bal)
{
	balance=bal;
}
void Account::setPassword(std::string pass)
{
	password=pass;
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
