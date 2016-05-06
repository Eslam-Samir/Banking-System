#include "CheckBalance.h"

namespace BankingSystem 
{

CheckBalance::CheckBalance(double AccountNum) : Transaction(AccountNum, TransactionType::query)
{
}
CheckBalance::CheckBalance(double id, time_t date, double balance, double AccountNum) : Transaction(id, date, balance, AccountNum, TransactionType::query)
{
}

void CheckBalance::modify()
{
	AccountManager* ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(getAccountNumber());
	setOldBalance(account->getBalance());
	account->addTransactionToHistory(getTransactionId());
	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "Your Current Balance: $" << account->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

void CheckBalance::printTransaction(std::ofstream &OutputFile)
{
}

}