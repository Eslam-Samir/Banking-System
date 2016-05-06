#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include <string>
namespace BankingSystem 
{
	enum EmpolyeeType {
	manager = 0,
	clerk = 1,
	cashier = 2
};
	enum Permission 
	{
		addAccount=0,
		removeAccount=1,
		allowWithdraw=2,
		allowDiposit=3,
		allowCheck=4,
		allowLoan=5,
		allowTransfer=6,
		startWithdraw=7,
		startDeposit=8,
		startCheck=9,
		startLoan=10,
		startTransfer=11,
		seeAllTransactions=12

	};
class Employee
{
private:
	int Id;
	std::string Username;
	std::string Password;
	EmpolyeeType Type;


public:
	Employee();
	Employee(std:: string Username,std::string Password,EmpolyeeType Type);
	
	std::string getUsername();
	std::string getPassword();
	EmpolyeeType getType();
	void setUsername(std::string Username);
	void setPassword(std::string Password);
protected:
	virtual Permission AccessPermitions() = 0;

};

}
#endif // __EMPLOYEE__