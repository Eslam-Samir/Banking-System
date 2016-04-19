#ifndef __ACCOUNTMANAGER__
#define __ACCOUNTMANAGER__

#include <list>
#include <string>
#include "Account.h"

class AccountManager
{
private:
	static AccountManager * accountManagerPtr;
	double NumberOfAccounts;
	AccountManager();
	
public:
	static AccountManager * getAccountManager();
	double getNumberOfAccounts();
	void addAccount(Account & user);
	void removeAccount(Account & user);
	void searchAccount(double account_no);
	void validateAccount(double account_no, std::string pass);

	void saveAccounts();
	void loadAccount();
};

#endif // __ACCOUNTMANAGER__
