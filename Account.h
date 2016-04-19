#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <list>
#include <string>
#include "Client.h"
class Account
{
private:
	double accountNumber;
	double balance;
	std::string password;
	double interestRate;
	Client owner;
	             ///   Transaction history    \\\\
	//a list that contains the history of transactions made by the clinet
	//the transaction class is not finished yet
	//list<trannsaction> transactionHistory;
public:
	Account(double acntnumber, double bal, std::string pass, Client & owner);
	void setBalance(double bal);
	void setPassword(std::string pass);
	void setOwner(Client owner);
	double getAccountNumber();
	double getBalance();
	std::string getPassword();
	Client & getOwner();
};

#endif // __ACCOUNT__

