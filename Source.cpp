#include <iostream>
#include "AccountManager.h"
#include "TransactionManager.h"
using namespace std;
using namespace BankingSystem;

void main()
{
	 
	AccountManager * ptr = AccountManager::getAccountManager();
	TransactionManager * transManager = TransactionManager::getTransactionManager();
	/*ptr->loadAccounts("hello.xml");
	transManager->loadTransactions("trans.xml");
	cout << transManager->searchTransaction(2566)->getFormatedDate();
	*/
	/*
	ptr->loadAccounts("hello.xml");
	Client* eslam = new Client(1, "Eslam Samir", "fsdags", "08/10/1994");
	transManager->addTransactionsRequest(eslam, TransactionType::deposit);
	transManager->serveDepositRequests();
	transManager->addTransactionsRequest(eslam, TransactionType::withdraw);
	transManager->serveWithdrawRequests();
	transManager->addTransactionsRequest(eslam, TransactionType::loan);
	transManager->serveLoanRequests();
	transManager->addTransactionsRequest(eslam, TransactionType::transfer);
	transManager->serveTransferRequests();
	transManager->addTransactionsRequest(eslam, TransactionType::query);
	transManager->serveBalanceRequests();
	
	transManager->saveTransactions("trans.xml");
	ptr->saveAccounts("accounts.xml");
	
	/*Client *eslam, *manar, *menna;
	eslam = new Client(1, "Eslam Samir", "fsdags", "08/10/1994");
	manar = new Client(2, "Manar Sherif", "fdhfdh", "25553532");
	menna = new Client(3, "Menna Tarek", "dfjjkfj", "373635");
	double acc1, acc2, acc3, acc4;
	acc1 = ptr->addAccount(200000,"hi",eslam);
	acc2 = ptr->addAccount(223,"hii",manar);
	acc3 = ptr->addAccount(0.5,"hiii",menna);
	acc4 = ptr->addAccount(223455,"sfgasg",eslam);
	transManager->addTransactionsRequest(eslam, TransactionType::deposit);
	transManager->serveDepositRequests
	
	ptr->searchAccount(acc1)->addTransactionToHistory(2);
	ptr->searchAccount(acc1)->addTransactionToHistory(3);
	cout << acc1 << endl;
	cout << acc2 << endl;
	cout << acc3 << endl;
	cout << acc4 << endl;
	
	cout << ptr->searchAccount(acc1)->getBalance() << endl;
	cout << ptr->searchAccount(acc2)->getBalance() << endl;
	cout << ptr->searchAccount(acc3)->getBalance() << endl;
	cout << ptr->validateAccount(acc1, "hi") << endl;
	cout << ptr->validateAccount(acc2, "8alat") << endl;
	cout << ptr->validateAccount(acc3, "hiii") << endl;
	/*
	ptr->removeAccount(ptr->searchAccount(acc1));
	ptr->removeAccount(ptr->searchAccount(acc2));
	ptr->removeAccount(ptr->searchAccount(acc3));
	
	
	cout << ptr->saveAccounts("hello.xml") << endl;
	
	ptr->loadAccounts("hello.xml");
	
	ptr->removeAccount(ptr->searchAccount(3156));
	ptr->removeAccount(ptr->searchAccount(6635));
	cout << ptr->searchAccount(6635) << endl;*/

	
	system("pause");
}
