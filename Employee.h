#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include <string>
namespace BankingSystem 
{
	enum EmployeeType {
		manager = 0,
		clerk,
		cashier
	};
	enum Permission 
	{
		addAccount = 0,
		removeAccount,
		allowWithdraw,
		allowDeposit,
		allowCheck,
		allowLoan,
		allowTransfer,
		startWithdraw,
		startDeposit,
		startCheck,
		startLoan,
		startTransfer,
		getAccountTransactions,
		addEmployee,
		removeEmployee,
		getTransactionReport
	};
class Employee
{
private:
	int Id;
	std::string Name;
	std::string Username;
	std::string Password;
	EmployeeType Type;


public:
	Employee(int id, std::string Name, std::string Username, std::string Password, EmployeeType Type);
	
	int getID();
	std::string getName();
	std::string getUsername();
	std::string getPassword();
	EmployeeType getType();
	void setPassword(std::string Password);
	virtual Permission AccessPermitions() = 0;

};

}
#endif // __EMPLOYEE__