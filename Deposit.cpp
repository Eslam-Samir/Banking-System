#include "Deposit.h"
#include "AccountManager.h"
#include "Account.h"



Deposit::Deposit(double x)
{
	amount = x;
}

double Deposit::getAmount()
{
	return amount;
}


void Deposit::modify()
{
	cout << "Enter the account number: ";
	double n;
	cin >> n;
	cout << "\n";

	AccountManager *ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(n);
	account->setBalance(account->getBalance() + amount);
	cout << "Your Transaction is completed your balance now is: " << account->getBalance();
}


		
	

