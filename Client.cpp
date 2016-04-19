#include "Client.h"

Client::Client()
{}

Client::Client(std::string n,std::string a,std::string d)
{
	name=n;
	address=a;
	dateOfBirth=d;
}
void Client::setName(std::string n){
	name=n;
}

void Client::setAdress(std::string a)
{
	address=a;
}

void Client::setDateOfBirth(std::string d)
{
	dateOfBirth=d;
}
void Client::addAccount(double accountNumber)
{
	myAccounts.push_back(accountNumber);
}
std::string Client::getName()
{
	return name;
}
std::string Client::getAddress()
{
	return address;
}
std::string Client::getDateOfBirth()
{
	return dateOfBirth;
}

std::vector<double> & Client::getMyAccounts()
{
	return myAccounts;
}
