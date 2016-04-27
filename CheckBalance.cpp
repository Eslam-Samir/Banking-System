#include "CheckBalance.h"

namespace BankingSystem 
{

CheckBalance::CheckBalance(double AccountNum) : Transaction(AccountNum, TransactionType::query)
{
}
CheckBalance::CheckBalance(double id, double AccountNum) : Transaction(id, AccountNum, TransactionType::query)
{
}

void CheckBalance::modify()
{
	AccountManager* ptr = AccountManager::getAccountManager();
	Account *account = ptr->searchAccount(getAccountNumber());
	account->addTransactionToHistory(getTransactionId());
	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "Your Current Balance: $" << account->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

}