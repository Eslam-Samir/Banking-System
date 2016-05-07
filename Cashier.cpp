#include "Cashier.h"
namespace BankingSystem 
{
Cashier::Cashier(int id, std::string name, std::string Username, std::string Password) : Employee(id, name, Username, Password, EmployeeType::cashier)
{}	

Permission Cashier::AccessPermitions()
{
	int a = 0;
	do
	{
		std::cout<<"Please choose an option"<< std::endl;
		std::cout<<"For alloing withdraw press 0"<< std::endl;
		std::cout<<"For allowing deposit press 1"<< std::endl;
		std::cout<<"For allowing checking press 2"<< std::endl;
		std::cout<<"For allowing a loan press 3"<< std::endl;
		std::cout<<"For allowing transfer press 4"<< std::endl;
		std::cout<<"For starting withdrawal press 5"<< std::endl;
		std::cout<<"For starting deposit press 6"<< std::endl;
		std::cout<<"For starting checking press 7"<< std::endl;
		std::cout<<"For starting loan press 8"<< std::endl;
		std::cout<<"For starting transfer press 9"<< std::endl;
		int a;
		std::cin>>a;
		if (a==0) return allowWithdraw;
		else if (a==1) return allowDeposit;
		else if (a==2) return allowCheck;
		else if (a==3) return allowLoan;
		else if (a==4) return allowTransfer;
		else if (a==5) return startWithdraw;
		else if (a==6) return startDeposit;
		else if (a==7) return startCheck;
		else if (a==8) return startLoan;
		else if (a==9) return startTransfer;
	} while(a < 0 || a > 9);
}
}