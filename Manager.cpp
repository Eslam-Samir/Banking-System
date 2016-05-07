#include "Manager.h"

namespace BankingSystem 
{
	Manager::Manager(int id, std::string name, std::string Username, std::string Password) : Employee(id, name, Username, Password, EmployeeType::manager)
{}	

Permission Manager::AccessPermitions()
{
	int a = 0;
	do
	{
		std::cout<<"Please choose an option" << std::endl;
		std::cout<<"For adding an employee press 0" << std::endl;
		std::cout<<"For removing an employee press 1" << std::endl;
		std::cout<<"To get Transactions Report press 2" << std::endl;
		int a;
		std::cin>>a;
		if (a==0) return addEmployee;
		else if (a==1) return removeEmployee;
		else if (a==2) return getTransactionReport;
	} while(a < 0 || a > 2);
}

}