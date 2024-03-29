#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <list>
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"

namespace BankingSystem
{

class Account
{
private:
	double accountNumber;
	double balance;
	std::string password;
	double interestRate;
	Client* owner;
	std::vector<double> transactions;

public:
	Account(double accountNum, double bal, std::string pass, Client* owner);
	void setBalance(double bal);
	void setPassword(std::string pass);
	void setOwner(Client* owner);
	void addTransactionToHistory(double transID);
	double getAccountNumber();
	double getBalance();
	std::string getPassword();
	Client* getOwner();
	std::vector<double> & getTransactionHistory();
	void printMyTransactionHistory();
	
};

}

#endif // __ACCOUNT__

