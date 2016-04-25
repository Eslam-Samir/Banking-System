#include "Transfer.h"
#include "AccountManager.h"
#include "Account.h"

Transfer::Transfer(double x = 0)
{
	amount = x;
}

double Transfer:: getAmount()
{
	return amount;
}
void Transfer:: setAmount(double x)
{
	amount = x;
}



void Transfer:: modify()
{
	//first account
	cout << "Enter your account number: ";
	double n;
	cin >> n;
	AccountManager *ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(n);
	account->setBalance(account->getBalance() - amount);

	if (account->getBalance() < amount)
		cout << "No enough money for the transfer";
	
	else
	{
		//second account
		cout << "Enter the second account number: ";
		double x;
		cin >> x;
		AccountManager *ptr2 = AccountManager::getAccountManager();
		Account *account2 = ptr2->searchAccount(x);

		//transfer
		account2->setBalance(account2->getBalance() + amount);

		cout << "Your Transaction is completed your balance now is: " << account->getBalance();
	}


}
