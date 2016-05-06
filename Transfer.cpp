#include "Transfer.h"

namespace BankingSystem
{

Transfer::Transfer(double from, double amount, double to) : Transaction(from, TransactionType::transfer)
{
	this->amount = amount;
	this->TransferredTo = to;
}
Transfer::Transfer(double id, time_t date, double balanceFrom, double balanceTo, double from, double amount, double to) : Transaction(id, date, balanceFrom, from, TransactionType::transfer)
{
	this->amount = amount;
	this->TransferredTo = to;
	this->OldBalanceTo = balanceTo;
}

double Transfer::getAmount()
{
	return amount;
}

double Transfer::getTransferredTo()
{
	return TransferredTo;
}
double Transfer::getOldBalanceTo()
{
	return OldBalanceTo;
}

void Transfer::modify()
{
	AccountManager* ptr = AccountManager::getAccountManager();
	Account *from = ptr->searchAccount(getAccountNumber());
	Account *to = ptr->searchAccount(TransferredTo);
	setOldBalance(from->getBalance());
	OldBalanceTo = to->getBalance();

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
void Transfer::printTransaction(std::ofstream &OutputFile)
{
	if (OutputFile)
    {
		OutputFile<<"Transfer Date: "<<getFormatedDate()<<"\n";
		OutputFile<<"Transfer to: "<<getOldBalanceTo()<<" total of "<<amount<<" $"<<"\n";
		//std::ostringstream strs;
		//strs << getOldBalance();
		//std::string str = strs.str();
		OutputFile << "Your old balance was: "<< getOldBalance()<<"\n";
		//strs.str("");
		//strs<<OldBalanceTo-amount;
		OutputFile<<"Your current balace is: "<<getOldBalance()-amount;
		//strs.str("");
        OutputFile.close();
    }
    
}
}