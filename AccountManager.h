
#ifndef __ACCOUNTMANAGER__
#define __ACCOUNTMANAGER__

#include <fstream>
#include <string>
#include <time.h>
#include "Account.h"
#include "Tree.h"

namespace BankingSystem
{
	
class AccountManager
{
private:
	double NumberOfAccounts;
	Tree * accounts; // to do tree will only fill the right half if accounts added to the tree in order
	static AccountManager * accountManagerPtr; // singleton
	AccountManager::AccountManager();
	
public:
	static AccountManager * AccountManager::getAccountManager();
	double AccountManager::addAccount(double bal, std::string pass, Client* owner);
	void AccountManager::removeAccount(Account* user);
	Account* AccountManager::searchAccount(double account_no);
	bool AccountManager::validateAccount(double account_no, std::string pass);
	double AccountManager::getNumberOfAccounts();
	bool AccountManager::saveAccounts(std::string filename);
	bool AccountManager::loadAccounts(std::string filename);
};
}

#endif // __ACCOUNTMANAGER__

