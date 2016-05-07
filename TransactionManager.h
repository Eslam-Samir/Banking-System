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
#include <fstream>

namespace BankingSystem
{

class TransactionManager 
{
private:
	TransactionManager();
	void createTransactionsXml(std::ofstream & outFile);
	void loadTransactionsXml(std::ifstream & inFile);
	std::string XmlParseTag(std::string & line, std::string TagName, std::stack<std::string> & s);

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
	Transaction* searchTransaction(double transactionID);
	bool saveTransactions(std::string filename);
	bool loadTransactions(std::string filename);
	void printTransactionsReport(std::string filename);

};

}

#endif // __TRANSACTIONMANAGER__