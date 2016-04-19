#include <list>
#include <string>
class Account
{
private:
	double accountNumber;
	double balance;
	std::string password;
	static double numberOfAccounts;//to make each account number unique
	double interestRate;
	             ///   Transaction history    \\\\
	//a list that contains the history of transactions made by the clinet
	//the transaction class is not finished yet
	//list<trannsaction> transactionHistory;
public:
	Account();
	Account(double acntnumber,double bal,std::string pass);
	void setBalance(double bal);
	void setPassword(std::string pass);
	double getAccountNumber();
	double getBalance();
	std::string getPassword();

};

