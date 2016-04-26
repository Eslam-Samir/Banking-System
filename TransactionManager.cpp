#include "TransactionManager.h"

namespace BankingSystem
{

TransactionManager* TransactionManager::transactionManagerPtr = nullptr; 

TransactionManager::TransactionManager()
{
	srand (time(NULL));
}
TransactionManager * TransactionManager::getTransactionManager()
{
	if(transactionManagerPtr == nullptr)
	{
		transactionManagerPtr = new TransactionManager();
	}
	return transactionManagerPtr;
}

void TransactionManager::serveWithdrawRequests()
{
	while (!withdraw.empty())
	{
		Client* client = withdraw.front();
		withdraw.pop();
		double num;
		std::string pass;
		std::cout << "Please enter the Account number: ";
		std::cin >> num; 
		std::cout << std::endl;

		std::cout << "Please enter your Password: ";
		std::cin >> pass; 
		std::cout << std::endl;

		AccountManager* ptr = AccountManager::getAccountManager();
		if(ptr->validateAccount(num, pass))
		{
			double amount;
			std::cout << "Please enter the amount you want to withdraw: ";
			std::cin >> amount;
			Transaction *transaction = new Withdraw(num, amount);
			transaction->modify();
			history[transaction->getTransactionId()] = transaction;
		}
	}
}

void TransactionManager::serveDepositRequests()
{
	while (!deposit.empty())
	{
		Client *client = deposit.front();
		deposit.pop();
		double num;
		std::string pass;
		std::cout << "Please enter the Account number: ";
		std::cin >> num; 
		std::cout << std::endl;

		std::cout << "Please enter your Password: ";
		std::cin >> pass; 
		std::cout << std::endl;

		AccountManager* ptr = AccountManager::getAccountManager();
		if(ptr->validateAccount(num, pass))
		{
			double amount;
			std::cout << "Enter the amount you want to deposit: ";
			std::cin >> amount;
			Transaction *transaction = new Deposit(num, amount);
			transaction->modify();

			history[transaction->getTransactionId()] = transaction;
		}
	}
}

void TransactionManager::serveTransferRequests()
{
	while (!transfer.empty())
	{
		Client *client = transfer.front();
		transfer.pop();
		double from, to;
		std::string pass;
		std::cout << "Please enter the Account number: ";
		std::cin >> from; 
		std::cout << std::endl;

		std::cout << "Please enter your Password: ";
		std::cin >> pass; 
		std::cout << std::endl;

		AccountManager *ptr = AccountManager::getAccountManager();
		if(ptr->validateAccount(from, pass))
		{
			std::cout << "Please the Account number transferred to: ";
			std::cin >> from; 
			std::cout << std::endl;
			if(ptr->searchAccount(from) != nullptr)
			{
				double amount;
				std::cout << "Enter amount: ";
				std::cin >> amount;
				Transaction *transaction = new Transfer(from, amount, to);
				transaction->modify();
				history[transaction->getTransactionId()] = transaction;
			}
		}
	}

}

void TransactionManager::serveBalanceRequests()
{
	double num;
	std::string pass;
	std::cout << "Please enter the Account number: ";
	std::cin >> num; 
	std::cout << std::endl;

	std::cout << "Please enter your Password: ";
	std::cin >> pass; 
	std::cout << std::endl;

	AccountManager* ptr = AccountManager::getAccountManager();
	if(ptr->validateAccount(num, pass))
	{
		Transaction *transaction = new CheckBalance(num);
		transaction->modify();
		history[transaction->getTransactionId()] = transaction;
	}
}

void TransactionManager::serveLoanRequests()
{
	while (!loan.empty())
	{
		Client *client = loan.front();
		loan.pop();
		double num;
		std::string pass;
		std::cout << "Please enter the Account number: ";
		std::cin >> num; 
		std::cout << std::endl;

		std::cout << "Please enter your Password: ";
		std::cin >> pass; 
		std::cout << std::endl;

		AccountManager* ptr = AccountManager::getAccountManager();
		if(ptr->validateAccount(num, pass))
		{
			double amount;
			std::cout << "Enter amount: ";
			std::cin >> amount;
			Transaction *transaction = new Loan(num, amount);
			transaction->modify();

			history[transaction->getTransactionId()] = transaction;
		}
	}

}

void TransactionManager::addTransactionsRequest(Client* client, TransactionType type)
{
	switch(type)
	{
	case TransactionType::withdraw:
		withdraw.push(client);
		break;
	case TransactionType::deposit:
		deposit.push(client);
		break;
	case TransactionType::transfer:
		transfer.push(client);
		break;
	case TransactionType::query:
		checkbalance.push(client);
		break;
	case TransactionType::loan:
		loan.push(client);
		break;

	}
}

}
