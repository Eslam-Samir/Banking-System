#include "AccountManager.h"

namespace BankingSystem
{

AccountManager* AccountManager::accountManagerPtr = nullptr; 

AccountManager::AccountManager()
{
	srand ((unsigned int)time(NULL));
	accounts = new Tree();
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

double AccountManager::addAccount(double bal, std::string pass, Client* owner)
{
	
	double accountNum = 0;
	for (int i = 0; i < 3; i++)
	{
		accountNum += rand() % 10;
		accountNum *= 10;
	}
	accountNum += rand() % 10;
	Account *tmp = new Account(accountNum, bal, pass, owner);
	accounts->insert(tmp);
	NumberOfAccounts++;

	std::cout << "Added a new account with the number: " << accountNum << std::endl;

	return accountNum;
}
void AccountManager::removeAccount(Account* user)
{
	if(user == nullptr)
		return;

	user->getOwner()->removeAccount(user->getAccountNumber());
	// delete client information from memory if he doesn't have other accounts
	if(user->getOwner()->getMyAccounts().size() == 0)
	{
		delete user->getOwner();
	}
	// remove account
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
bool AccountManager::saveAccounts(std::string filename)
{
	if(accounts->isEmpty())
		return false;
	if((filename.length() < 5) || (filename.substr(filename.length() - 4, 4) != ".xml"))
	{
		std::cout << "Wrong file extension \"must be an xml file\"" << std::endl;
		return false;
	}

	std::ofstream outFile(filename);
	if(!outFile.is_open())
		return false;

	outFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	std::stringstream ss;
	ss << getNumberOfAccounts(); // convert to string
	outFile << "<NumberOfAccounts>" + ss.str() + "</NumberOfAccounts>\n";
	ss.str(std::string()); // clear string stream
	accounts->createAccountsXml(outFile);
	outFile.close();
	return true;
}

bool AccountManager::loadAccounts(std::string filename)
{
	if((filename.length() < 5) || (filename.substr(filename.length() - 4, 4) != ".xml"))
	{
		std::cout << "Wrong file extension \"must be an xml file\"" << std::endl;
		return false;
	}

	std::ifstream inFile(filename);
	if(!inFile.is_open())
		return false;

	NumberOfAccounts = accounts->loadAccountsXml(inFile);
	inFile.close();
	return true;
}
}
