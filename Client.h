#ifndef __CLIENT__
#define __CLIENT__

#include <string>
#include <vector>

class Client
{
private:
	std::string name;
	std::string address;
	std::string dateOfBirth;
	std::vector<double> myAccounts;

public:
	Client();
	Client(std::string n,std::string a,std::string d);
	void setName(std::string n);
	void setAdress(std::string a);
	void setDateOfBirth(std::string d);
	void addAccount(double accountNumber);
	std::string getName();
	std::string getAddress();
	std::string getDateOfBirth();
	std::vector<double> & getMyAccounts();

};

#endif // __CLIENT__