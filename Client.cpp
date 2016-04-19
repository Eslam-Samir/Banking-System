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
void Client::setMyAccounts(Account a)
{
	myAccounts.push_front(a);
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

Account* Client::getMyAccounts()
{
	std::list<Account>::iterator i=myAccounts.begin();
	return &*i;
}
