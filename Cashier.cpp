#include "Cashier.h"
namespace BankingSystem 
{
	Permission Cashier::AccessPermitions()
	{
		std::cout<<"Please choose an option \nFor alloing withdraw  press 0\nFor allowing deposit press 1\n";
		std::cout<<"For allowing checking press 2\nFor allowing a loan press 3\n";
		std::cout<<"For allowing transfer press 4\nFor starting withdrawal press 5\n";
		std::cout<<"For starting deposit press 6\nFor starting checking press 7\n";
		std::cout<<"For starting loan press 8\nFot starting transfer press 9\n";
		int a;
		std::cin>>a;
		if (a==0) return allowWithdraw;
		else if (a==1) return allowDiposit;
		else if (a==2) return allowCheck;
		else if (a==3) return allowLoan;
		else if (a==4) return allowTransfer;
		else if (a==5) return startWithdraw;
		else if (a==6) return startDeposit;
		else if (a==7) return startCheck;
		else if (a==8) return startLoan;
		else if (a==9) return startTransfer;
	}
}