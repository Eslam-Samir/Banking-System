#include"Loan.h"
#include "AccountManager.h"
#include "Account.h"



Loan::Loan(double x = 0)
{
	amount = x;
}

double Loan:: getAmount()
{
	return amount;
}
void Loan:: setAmount(double x)
{
	amount = x;
}




void Loan::modify()
{
	cout << "Enter the accout number: ";
	double n;
	cin >> n;
	cout << "Is the loan accepted?";
	bool accept;
	cin >> accept;
	if (accept == true)
	{

		AccountManager *ptr = AccountManager::getAccountManager();
		Account *account = ptr->searchAccount(n);
		account->setBalance(account->getBalance() + amount);
		cout << "Your Transaction is completed your balance now is: " << account->getBalance();
	}
	else
		cout << "Loan request was refused";
}
