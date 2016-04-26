#ifndef __TRANSACTIONMANAGER__
#define __TRANSACTIONMANAGER__

#include <iostream>
#include <queue>
#include "Client.h"
#include "Account.h"
#include "AccountManager.h"
#include "Transaction.h"
#include "Withdraw.h"
#include "Deposit.h"
#include "Loan.h"
#include "CheckBalance.h"
#include "Transfer.h"
#include <map>
#include <utility>

namespace BankingSystem
{

class TransactionManager 
{
private:
	TransactionManager();

	std::queue<Client*> withdraw;
	std::queue<Client*> deposit;
	std::queue<Client*> transfer;
	std::queue<Client*> checkbalance;
	std::queue<Client*> loan;

	std::map<double, Transaction*> history; // key-> transaction id, value -> transaction ptr

	static TransactionManager* transactionManagerPtr; // singleton
	
public:
	static TransactionManager * getTransactionManager();
	void serveWithdrawRequests();
	void serveDepositRequests();
	void serveTransferRequests();
	void serveBalanceRequests();
	void serveLoanRequests();
	void addTransactionsRequest(Client* client, TransactionType type);

};

}

#endif // __TRANSACTIONMANAGER__