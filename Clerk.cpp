#include "Clerk.h"
namespace BankingSystem 
{
Clerk:: Clerk(int id, std::string name, std::string Username, std::string Password) : Employee(id, name, Username, Password, EmployeeType::clerk)
{}	

Permission Clerk::AccessPermitions()
{
	int a = 0;
	do
	{
		std::cout<<"Please choose an option"<< std::endl;
		std::cout<<"For adding a client account press 0"<< std::endl;
		std::cout<<"For removing client account press 1"<< std::endl;
		std::cout<<"For client transactions information press 2"<< std::endl;
		int a;
		std::cin>>a;
		if (a==0) return addAccount;
		else if (a==1) return removeAccount;
		else if (a==2) return getAccountTransactions;
	} while(a < 0 || a > 2);
}

}