// to do fix linker problem

/*#include "AccountManager.h"

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
}*/