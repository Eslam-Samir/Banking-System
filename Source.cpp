#include <iostream>
#include "AccountManager.h"
#include "TransactionManager.h"
#include "EmployeeManager.h"

using namespace std;
using namespace BankingSystem;

void main()
{
	AccountManager * accountManager = AccountManager::getAccountManager();
	TransactionManager * transactionManager = TransactionManager::getTransactionManager();
	EmployeeManager* employeeManager = EmployeeManager::getEmployeeManager();
	
	accountManager->loadAccounts("accounts.xml");
	transactionManager->loadTransactions("trans.xml");
	employeeManager->loadEmployees("employees.xml");

	Employee* currentEmployee = nullptr;
	bool LoggedIn = false;
	Permission option;

	cout << "Employee Login:" << endl;
	do
	{
		string username, password;
		cout << "Please enter your username: ";
		cin >> username;
		cout << "Please enter your password: ";
		cin >> password;
		currentEmployee = employeeManager->EmployeeLogin(username, password);
		cout << endl;
	} while(currentEmployee == nullptr);

	LoggedIn = true;
	cout << endl;

	while(LoggedIn)
	{
		option = currentEmployee->AccessPermitions();

		switch(option)
		{
		case addEmployee:
			{
				string username, password, name;
				int type;
				cout << "\nPlease enter the employee name: ";
				cin >> name;
				cout << "\nPlease enter the employee username: ";
				cin >> username;
				cout << "\nPlease enter the employee password: ";
				cin >> password;
				do
				{
					cout << "\nPlease enter the employee type (1. manager - 2. clerk - 3. cashier): ";
					cin >> type;
					if(type == 1)
						employeeManager->addEmployee(name, username, password, EmployeeType::manager);
					else if(type == 2)
						employeeManager->addEmployee(name, username, password, EmployeeType::clerk);
					else if(type == 3)
						employeeManager->addEmployee(name, username, password, EmployeeType::cashier);
				} while(type < 1 || type > 3);
				cout << endl;
			}
			break;
		case removeEmployee:
			{
				string username, password;
				cout << "\nPlease enter the employee username: ";
				cin >> username;
				cout << "\nPlease enter the employee password: ";
				cin >> password;
				if(!employeeManager->removeEmployee(username, password))
					cout << "\nCouldn't remove the employee (Wrong username or password) ";
				cout << endl;
			}
			break;
		case getTransactionReport:
			{
				string filename;
				cout << "\nPlease enter the report file name: ";
				cin >> filename;
				transactionManager->printTransactionsReport(filename + ".txt");
				cout << endl;
			}
			break;
		case addAccount:
			{
				double num, balance, clientID;
				int oldClient;
				string password, newpass, name, dateOfBirth, address;
				Account* account;
				Client* client;
				do
				{
					cout << "\nDo you already have an account (1. yes 2. no)";
					cin >> oldClient;

					if(oldClient == 1)
					{
						cout << "\nPlease enter the account number: ";
						cin >> num;
						cout << "\nPlease enter the account password: ";
						cin >> password;
						if(accountManager->validateAccount(num, password))
						{
							account = accountManager->searchAccount(num);
							client = account->getOwner();
						}
						else
							cout << "\nWrong account number or password ";
					}
					else if(oldClient == 2)
					{
						cout << "\nEnter the client ID: ";
						cin >> clientID;
						cout << "\nEnter the client name: ";
						cin >> name;
						cout << "\nEnter the client address: ";
						cin >> address;
						cout << "\nEnter the client date of birth: ";
						cin >> dateOfBirth;
						client = new Client(clientID, name, address, dateOfBirth);
					}
				} while(oldClient != 1 || oldClient != 2);
				account = accountManager->searchAccount(num);
				cout << "\nEnter the new account information: ";
				cout << "\nThe new account base balance: ";
				cin >> balance;
				cout << "\nThe new account password: ";
				cin >> password;
				if(client != nullptr)
					accountManager->addAccount(balance, newpass, client);
				cout << endl;
			}
			break;
		case removeAccount:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				cout << "\nPlease enter the account password: ";
				cin >> password;
				if(accountManager->validateAccount(num, password))
				{
					account = accountManager->searchAccount(num);
					accountManager->removeAccount(account);
				}
				else
					cout << "\nWrong account number or password ";
				cout << endl;
			}
			break;
		case getAccountTransactions:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				cout << "\nPlease enter the account password: ";
				cin >> password;
				if(accountManager->validateAccount(num, password))
				{
					account = accountManager->searchAccount(num);
					account->printMyTransactionHistory();
				}
				else
					cout << "\nWrong account number or password ";
				cout << endl;
			}
			break;
		case addWithdraw:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				account = accountManager->searchAccount(num);

				if(account != nullptr)
					transactionManager->addTransactionsRequest(account->getOwner(), TransactionType::withdraw);
				else
					cout << "\nWrong account number";
				cout << endl;
			}
			break;
		case addDeposit:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				account = accountManager->searchAccount(num);

				if(account != nullptr)
					transactionManager->addTransactionsRequest(account->getOwner(), TransactionType::deposit);
				else
					cout << "\nWrong account number";
				cout << endl;
			}
			break;
		case addCheck:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				account = accountManager->searchAccount(num);

				if(account != nullptr)
					transactionManager->addTransactionsRequest(account->getOwner(), TransactionType::query);
				else
					cout << "\nWrong account number";
				cout << endl;
			}
			break;
		case addLoan:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				account = accountManager->searchAccount(num);

				if(account != nullptr)
					transactionManager->addTransactionsRequest(account->getOwner(), TransactionType::loan);
				else
					cout << "\nWrong account number";
				cout << endl;
			}
			break;
		case addTransfer:
			{
				double num;
				string password;
				Account* account;
				cout << "\nPlease enter the account number: ";
				cin >> num;
				account = accountManager->searchAccount(num);

				if(account != nullptr)
					transactionManager->addTransactionsRequest(account->getOwner(), TransactionType::transfer);
				else
					cout << "\nWrong account number";
				cout << endl;
			}
			break;
		case startWithdraw:
			transactionManager->serveWithdrawRequests();
			break;
		case startDeposit:
			transactionManager->serveDepositRequests();
			break;
		case startCheck:
			transactionManager->serveBalanceRequests();
			break;
		case startLoan:
			transactionManager->serveLoanRequests();
			break;
		case startTransfer:
			transactionManager->serveTransferRequests();
			break;

		case loadAccounts:
			{
			string filename;
			cout << "\nPlease enter the accounts file name: ";
			cin >> filename;
			accountManager->loadAccounts(filename + ".xml");
			}
			break;
		case loadTransactions:
			{
			string filename;
			cout << "\nPlease enter the accounts file name: ";
			cin >> filename;
			transactionManager->loadTransactions(filename + ".xml");
			}
			break;
		case loadEmployees:
			{
			string filename;
			cout << "\nPlease enter the accounts file name: ";
			cin >> filename;
			employeeManager->loadEmployees(filename + ".xml");
			}
			break;
		case saveAccounts:
			{
			string filename;
			cout << "\nPlease enter the accounts file name: ";
			cin >> filename;
			accountManager->saveAccounts(filename + ".xml");
			}
			break;
		case saveTransactions:
			{
			string filename;
			cout << "\nPlease enter the accounts file name: ";
			cin >> filename;
			transactionManager->saveTransactions(filename + ".xml");
			}
			break;
		case saveEmployees:
			{
			string filename;
			cout << "\nPlease enter the accounts file name: ";
			cin >> filename;
			employeeManager->saveEmployees(filename + ".xml");
			}
			break;
		case logout:
			LoggedIn = false;
			break;
		}
	}
	int x;
	cout << "Do you want to save (1. yes 2. no) ";
	cin >> x;
	if(x == 1)
	{
		accountManager->saveAccounts("accounts.xml");
		transactionManager->saveTransactions("trans.xml");
		employeeManager->saveEmployees("employees.xml");
	}
	system("pause");
}
