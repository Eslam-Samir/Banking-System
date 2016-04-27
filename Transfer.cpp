#include "Transfer.h"

namespace BankingSystem
{

Transfer::Transfer(double from, double amount, double to) : Transaction(from, TransactionType::transfer)
{
	this->amount = amount;
	this->TransferredTo = to;
}
Transfer::Transfer(double id, double from, double amount, double to) : Transaction(id, from, TransactionType::transfer)
{
	this->amount = amount;
	this->TransferredTo = to;
}

double Transfer::getAmount()
{
	return amount;
}

double Transfer::getTransferredTo()
{
	return TransferredTo;
}

void Transfer::modify()
{
	AccountManager* ptr = AccountManager::getAccountManager();
	Account *from = ptr->searchAccount(getAccountNumber());
	Account *to = ptr->searchAccount(TransferredTo);
	if (from->getBalance() < amount)
	{
		std::cout << "No enough money for the transfer";
		return;
	}
	//transfer
	from->setBalance(from->getBalance() - amount);
	to->setBalance(to->getBalance() + amount);
	from->addTransactionToHistory(getTransactionId());
	to->addTransactionToHistory(getTransactionId());
	std::cout << "The Transaction is Completed" << std::endl;
	std::cout << "$" << amount << " Transferred from " << getAccountNumber() << " to " << TransferredTo << std::endl;
	std::cout << "Your New Balance: $" << from->getBalance() << std::endl;
	std::cout << "Transaction Number: " << getTransactionId() << std::endl;
}

}