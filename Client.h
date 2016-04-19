#include <string>
#include <list>
#include "Account.h"
class Client
{
private:
	std::string name;
	std::string address;
	std::string dateOfBirth;
	std::list<Account> myAccounts;

public:
	Client();
	Client(std::string n,std::string a,std::string d);
	void setName(std::string n);
	void setAdress(std::string a);
	void setDateOfBirth(std::string d);
	void setMyAccounts(Account a);
	std::string getName();
	std::string getAddress();
	std::string getDateOfBirth();
	Account* getMyAccounts();

};

