#include "Withdraw.h"

namespace BankingSystem
{

Withdraw ::Withdraw(double AccountNum, double amount) : Transaction(AccountNum, TransactionType::withdraw)
{
	this->amount = amount;
}
Withdraw ::Withdraw(double id, double AccountNum, double amount) : Transaction(id, AccountNum, TransactionType::withdraw)
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

	if (account->getBalance() < amount)
	{
		std::cout << "No enough money for the withdraw";
		return;
	}
	account->setBalance(account->getBalance() - amount);
	account->addTransactionToHistory(getTransactionId());
	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "You Have Withdrawn: $" << amount << std::endl;
	std::cout << "Your New Balance: $" << account->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

}