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
		std::cout<<"Please choose an option: "<< std::endl;
		std::cout<<"1. Add a Withdrawal Request"<< std::endl;
		std::cout<<"2. Add a Deposit Request"<< std::endl;
		std::cout<<"3. Add a Checking Request"<< std::endl;
		std::cout<<"4. Add a Loan Request"<< std::endl;
		std::cout<<"5. Add a Transfer Request"<< std::endl;
		std::cout<<"6. Start Withdrawal Transactions"<< std::endl;
		std::cout<<"7. Start Deposit Transactions"<< std::endl;
		std::cout<<"8. Start Checking Transactions"<< std::endl;
		std::cout<<"9. Start Loan Transactions"<< std::endl;
		std::cout<<"10. Start Transfer Transactions"<< std::endl;
		std::cout<<"11. Save Transactions"<< std::endl;
		std::cout<<"12. Logout"<< std::endl;
		int a;
		std::cin>>a;
		if (a==1) return addWithdraw;
		else if (a==2) return addDeposit;
		else if (a==3) return addCheck;
		else if (a==4) return addLoan;
		else if (a==5) return addTransfer;
		else if (a==6) return startWithdraw;
		else if (a==7) return startDeposit;
		else if (a==8) return startCheck;
		else if (a==9) return startLoan;
		else if (a==10) return startTransfer;
		else if (a==11) return saveTransactions;
		else if (a==12) return logout;
	} while(a < 1 || a > 12);
	return logout;
}
}