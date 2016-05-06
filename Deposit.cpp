
#include "Deposit.h"
namespace BankingSystem
{

Deposit::Deposit(double AccountNum, double amount) : Transaction(AccountNum, TransactionType::deposit)
{
	this->amount = amount;
}
Deposit::Deposit(double id, time_t date, double balance, double AccountNum, double amount) : Transaction(id, date, balance, AccountNum, TransactionType::deposit)
{
	this->amount = amount;
}
double Deposit::getAmount()
{
	return amount;
}
void Deposit::modify()
{
	AccountManager* ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(getAccountNumber());
	setOldBalance(account->getBalance());
	account->setBalance(account->getBalance() + amount);
	account->addTransactionToHistory(getTransactionId());

	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "You Have Deposited $" << amount << std::endl;
	std::cout << "Your New Balance: $" << account->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

void Deposit::printTransaction(std::ofstream &OutputFile)
{
	 if (OutputFile)
    {
		OutputFile<<"Deposit Date: "<<getFormatedDate()<<"\n";
		OutputFile<<"Deposit amount of "<<amount<<" $"<<"\n";
		OutputFile << "Your old balance was: "<< getOldBalance()<<"\n";
		OutputFile<<"Your current balace is: "<<getOldBalance()+amount;
        OutputFile.close();
    }
}

}
		
	

