#include"Loan.h"

namespace BankingSystem
{

Loan::Loan(double AccountNum, double amount) : Transaction(AccountNum, TransactionType::loan)
{
	this->amount = amount;
}

double Loan:: getAmount()
{
	return amount;
}

void Loan::modify()
{
	std::cout << "Is " + name + "loan accepted?" << std::endl;
	bool accept;
	std::cin >> accept;
	if (accept == true)
	{
		std::cout << "You loan request is granted" << std::endl;
		AccountManager* ptr = AccountManager::getAccountManager();
		Account *account = ptr->searchAccount(getAccountNumber());
		account->setBalance(account->getBalance() + amount);
		account->addTransactionToHistory(getTransactionId());
		std::cout << "The Transaction is Completed" << std::endl;
		std::cout << "You Loaned $" << amount << "from The Bank" << std::endl;
		std::cout << "Your New Balance: $" << account->getBalance() << std::endl;
		std::cout << "Transaction Number: " << getTransactionId() << std::endl;
	}
	else
		std::cout << "Loan request was refused";
}

}