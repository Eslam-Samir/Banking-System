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
		std::cout<<"Please choose an option: "<< std::endl;
		std::cout<<"1. Add a Client Account"<< std::endl;
		std::cout<<"2. Remove a Client Account"<< std::endl;
		std::cout<<"3. Print Client Transactions Information"<< std::endl;
		std::cout<<"4. Load Clients Accounts"<< std::endl;
		std::cout<<"5. Load Transactions"<< std::endl;
		std::cout<<"6. Save Clients Accounts"<< std::endl;
		std::cout<<"7. Logout"<< std::endl;
		int a;
		std::cin>>a;
		if (a==1) return addAccount;
		else if (a==2) return removeAccount;
		else if (a==3) return getAccountTransactions;
		else if (a==4) return loadAccounts;
		else if (a==5) return loadTransactions;
		else if (a==6) return saveTransactions;
		else if (a==7) return logout;
	} while(a < 1 || a > 7);
	return logout;
}

}