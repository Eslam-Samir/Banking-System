#include "Withdraw.h"

namespace BankingSystem
{

Withdraw ::Withdraw(double AccountNum, double amount) : Transaction(AccountNum, TransactionType::withdraw)
{
	this->amount = amount;
}
Withdraw ::Withdraw(double id, time_t date, double balance, double AccountNum, double amount) : Transaction(id, date, balance, AccountNum, TransactionType::withdraw)
{
	this->amount = amount;
}

double Withdraw:: getAmount()
{
	return amount;
}
void Withdraw:: modify()
{
	AccountManager* ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(getAccountNumber());
	setOldBalance(account->getBalance());

	if (account->getBalance() < amount)
	{
		std::cout << "No enough money for the withdraw" << std::endl;
		return;
	}
	account->setBalance(account->getBalance() - amount);
	account->addTransactionToHistory(getTransactionId());
	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "You Have Withdrawn: $" << amount << std::endl;
	std::cout << "Your New Balance: $" << account->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

void Withdraw::printTransaction(std::ofstream &OutputFile)
{
	 if (OutputFile)
    {
		OutputFile<<"Withdraw Date: "<<getFormatedDate()<<"\n";
		OutputFile<<"Withdraw amount of "<<amount<<" $"<<"\n";
		OutputFile << "Your old balance was: "<< getOldBalance()<<"\n";
		OutputFile<<"Your current balace is: "<<getOldBalance()-amount<<"\n";
  
    }
}

}