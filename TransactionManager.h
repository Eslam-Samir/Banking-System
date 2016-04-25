#pragma once
#include <iostream>
#include <queue>
#include "Client.h"
#include "Account.h"
#include "AccountManager.h"
#include "Transaction.h"
#include "Withdraw.h"
#include "Deposit.h"
#include "Loan.h"
#include "Transfer.h"
#include <map>
#include <utility>



using namespace std;

class TransactionManager 
{
private:
	queue<Client> withdraw;
	queue<Client> deposit;
	queue<Client> transfer;
	queue<Client> loan;
	queue<Client> checkbalance;
	map<double, Transaction*> history;
	double transNum;
	

	/*enum trasnType {
		withdraw = 1,
		deposit = 2,
		transfer = 3,
		loan = 4,
		query = 5
	};
*/

public:
	TransactionManager();
	void withdrawRequest();
	void depositRequest();
	void transferRequest();
	void queryRequest();
	void loanRequest();
	void initiateTransaction();



};

TransactionManager::TransactionManager()
{
	 transNum = 0;
	for (int i = 0; i < 3; i++)
	{
		transNum += rand() % 10;
		transNum *= 10;
	}
	transNum += rand() % 10;


}



void TransactionManager::withdrawRequest()
{
	while (!withdraw.empty())
	{
		Client *client = &withdraw.front();
		withdraw.pop();
		int n;
		cout << "Please enter the Account number: ";
		cin >> n; cout << "\n";
		AccountManager *ptr = AccountManager::getAccountManager();
		Account *account = ptr->searchAccount(n);
		if (account != nullptr)
		{
			double x;
			cout << "Enter amount: ";
			cin >> x;
			Transaction *trans = new Withdraw(x);
			trans->modify();

			history[transNum] = trans;
		}



	}
}

void TransactionManager::depositRequest()
{
	while (!deposit.empty())
	{
		Client *client = &deposit.front();
		deposit.pop();
		int n;
		cout << "Please enter the Account number: ";
		cin >> n; cout << "\n";
		AccountManager *ptr = AccountManager::getAccountManager();
		Account *account = ptr->searchAccount(n);
		if (account != nullptr)
		{
			double x;
			cout << "Enter amount: ";
			cin >> x;
			Transaction *trans = new Deposit(x);
			trans->modify();

			history[transNum] = trans;
		}
	}
}

void TransactionManager::transferRequest()
{
	while (!transfer.empty())
	{
		Client *client = &transfer.front();
		transfer.pop();
		int n;
		cout << "Please enter the Account number: ";
		cin >> n; cout << "\n";
		AccountManager *ptr = AccountManager::getAccountManager();
		Account *account = ptr->searchAccount(n);
		if (account != nullptr)
		{
			double x;
			cout << "Enter amount: ";
			cin >> x;
			Transaction *trans = new Transfer(x);
			trans->modify();

			history[transNum] = trans;
		}
	}

}

void TransactionManager::queryRequest()
{

}

void TransactionManager::loanRequest()
{
	while (!loan.empty())
	{
		Client *client = &loan.front();
		loan.pop();
		int n;
		cout << "Please enter the Account number: ";
		cin >> n; cout << "\n";
		AccountManager *ptr = AccountManager::getAccountManager();
		Account *account = ptr->searchAccount(n);
		if (account != nullptr)
		{
			double x;
			cout << "Enter amount: ";
			cin >> x;
			Transaction *trans = new Loan(x);
			trans->modify();

			history[transNum] = trans;
		}
	}

}

void TransactionManager::initiateTransaction()
{

}