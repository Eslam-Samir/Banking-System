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
		std::cout<<"Please choose an option: " << std::endl;
		std::cout<<"1. Add an Employee" << std::endl;
		std::cout<<"2. Removing an Employee" << std::endl;
		std::cout<<"3. Print Transactions Report" << std::endl;
		std::cout<<"4. Load Employees Accounts" << std::endl;
		std::cout<<"5. Load Transactions" << std::endl;
		std::cout<<"6. Save Employees Accounts" << std::endl;
		std::cout<<"7. To Logout"<< std::endl;
		int a;
		std::cin>>a;
		if (a==1) return addEmployee;
		else if (a==2) return removeEmployee;
		else if (a==3) return getTransactionReport;
		else if (a==4) return loadEmployees;
		else if (a==5) return loadTransactions;
		else if (a==6) return saveEmployees;
		else if (a==7) return logout;
	} while(a < 1 || a > 7);
	return logout;
}

}