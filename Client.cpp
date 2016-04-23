#include "Client.h"

Client::Client()
{}

Client::Client(double id, std::string n,std::string a,std::string d)
{
	clientID=id;
	name=n;
	address=a;
	dateOfBirth=d;
}
void Client::setClientID(double id){
	clientID=id;
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
void Client::removeAccount(double accountNumber)
{
	std::vector<double>::iterator it = myAccounts.begin();
	for(; it < myAccounts.end(); it++)
	{
		if(*it == accountNumber)
		{
			myAccounts.erase(it); // remove account from client
			break;
		}
	}
}
double Client::getClientID()
{
	return clientID;
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
