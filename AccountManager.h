#ifndef __ACCOUNTMANAGER__
#define __ACCOUNTMANAGER__

#include <string>
#include "Account.h"
#include "Tree.h"

class AccountManager
{
private:
	double NumberOfAccounts;
	Tree * accounts; // to do tree will only fill the right half if accounts added to the tree in order
	static AccountManager * accountManagerPtr;
	AccountManager();
	
public:
	
	static AccountManager * getAccountManager();
	double getNumberOfAccounts();
	double addAccount(double bal, std::string pass, Client* owner);
	void removeAccount(Account* user);
	Account* searchAccount(double account_no);
	bool validateAccount(double account_no, std::string pass);

	void saveAccounts();
	void loadAccount();
};

AccountManager::AccountManager()
{
	accounts = new Tree();
	NumberOfAccounts = 0;
}

inline AccountManager * AccountManager::getAccountManager()
{
	if(accountManagerPtr == nullptr)
	{
		accountManagerPtr = new AccountManager();
	}
	return accountManagerPtr;
}

double AccountManager::addAccount(double bal, std::string pass, Client* owner)
{
	Account *tmp = new Account(NumberOfAccounts, bal, pass, owner);
	accounts->insert(tmp);
	NumberOfAccounts++;
	return tmp->getAccountNumber();
}
void AccountManager::removeAccount(Account* user)
{
	accounts->remove(user);
	NumberOfAccounts--;
}
Account* AccountManager::searchAccount(double account_no)
{
	return accounts->search(account_no);
}
bool AccountManager::validateAccount(double account_no, std::string pass)
{
	Account* tmp = accounts->search(account_no);
	if(tmp == nullptr)
	{
		return false;
	}
	else if(tmp->getPassword() == pass)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double AccountManager::getNumberOfAccounts()
{
	return NumberOfAccounts;
}

#endif // __ACCOUNTMANAGER__
