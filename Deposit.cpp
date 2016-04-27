#include "Deposit.h"

namespace BankingSystem
{

Deposit::Deposit(double AccountNum, double amount) : Transaction(AccountNum, TransactionType::deposit)
{
	this->amount = amount;
}
Deposit::Deposit(double id, double AccountNum, double amount) : Transaction(id, AccountNum, TransactionType::deposit)
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
	account->setBalance(account->getBalance() + amount);
	account->addTransactionToHistory(getTransactionId());

	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "You Have Deposited $" << amount << std::endl;
	std::cout << "Your New Balance: $" << account->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

}
		
	

