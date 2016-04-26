#ifndef __CLIENT__
#define __CLIENT__

#include <string>
#include <vector>

namespace BankingSystem
{

class Client
{
private:
	double clientID;
	std::string name;
	std::string address;
	std::string dateOfBirth;
	std::vector<double> myAccounts;

public:
	Client();
	Client(double id, std::string n,std::string a,std::string d);
	void setClientID(double id);
	void setName(std::string n);
	void setAdress(std::string a);
	void setDateOfBirth(std::string d);
	void addAccount(double accountNumber);
	void removeAccount(double accountNumber);
	double getClientID();
	std::string getName();
	std::string getAddress();
	std::string getDateOfBirth();
	std::vector<double> & getMyAccounts();

};

}

#endif // __CLIENT__