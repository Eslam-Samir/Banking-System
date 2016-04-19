#include "AccountManager.h"

AccountManager::AccountManager()
{
	NumberOfAccounts = 0;
}

AccountManager * AccountManager::getAccountManager()
{
	if(accountManagerPtr == nullptr)
	{
		accountManagerPtr = new AccountManager();
	}
	return accountManagerPtr;
}

double AccountManager::getNumberOfAccounts()
{
	return NumberOfAccounts;
}