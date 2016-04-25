#include "Withdraw.h"
#include "AccountManager.h"
#include "Account.h"

Withdraw ::Withdraw(double x )
{
	amount = x;
}

double Withdraw:: getAmount()
{
	return amount;
}
void Withdraw:: setAmount(double x)
{
	amount = x;
}


void Withdraw:: modify()
{
	cout << "Enter the account number: ";
	double n;
	cin >> n;
	AccountManager *ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(n);

	if (account->getBalance() < amount)
	{

		cout << "No enough money for the withdraw";
	}

	else
	{
		account->setBalance(account->getBalance() - amount);
		cout << "your transaction is completed your balance now is " << account->getBalance();
	}
}

