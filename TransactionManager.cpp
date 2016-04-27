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
			std::cin >> to; 
			std::cout << std::endl;
			if(ptr->searchAccount(to) != nullptr)
			{
				double amount;
				std::cout << "Enter the amount you want to transfer: ";
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
			std::cout << "Enter the amount requested: ";
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

Transaction* TransactionManager::searchTransaction(double transactionID)
{
	std::map<double, Transaction*>::iterator it = history.find(transactionID);
	if(it == history.end())
	{
		return nullptr;
	}
	else
	{
		return it->second;
	}
}
bool TransactionManager::saveTransactions(std::string filename)
{
	if(history.empty())
		return false;
	if((filename.length() < 5) || (filename.substr(filename.length() - 4, 4) != ".xml"))
	{
		std::cout << "Wrong file extension \"must be an xml file\"" << std::endl;
		return false;
	}

	std::ofstream outFile(filename);
	if(!outFile.is_open())
		return false;

	outFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	createXml(outFile);
	return true;
}
bool TransactionManager::loadTransactions(std::string filename)
{
	if((filename.length() < 5) || (filename.substr(filename.length() - 4, 4) != ".xml"))
	{
		std::cout << "Wrong file extension \"must be an xml file\"" << std::endl;
		return false;
	}

	std::ifstream inFile(filename);
	if(!inFile.is_open())
		return false;

	loadXml(inFile);
	return true;
}

void TransactionManager::createXml(std::ofstream & outFile)
{
	std::map<double, Transaction*>::iterator it = history.begin();
	while(it != history.end())
	{
		std::stringstream ss;
		Transaction * transaction = it->second;
		TransactionType type = transaction->getType();
		switch(type)
		{
		case TransactionType::deposit:
			outFile << "<Deposit>\n";
			break;
		case TransactionType::loan:
			outFile << "<Loan>\n";
			break;
		case TransactionType::query:
			outFile << "<BalanceCheck>\n";
			break;
		case TransactionType::transfer:
			outFile << "<Transfer>\n";
			break;
		case TransactionType::withdraw:
			outFile << "<Withdraw>\n";
			break;
		}

		ss << transaction->getTransactionId(); // convert to string
		outFile << "<TransactionID>" + ss.str() + "</TransactionID>\n";
		ss.str(std::string()); // clear string stream

		ss << transaction->getAccountNumber(); // convert to string
		outFile << "<AccountNumber>" + ss.str() + "</AccountNumber>\n";
		ss.str(std::string()); // clear string stream
		
		//outFile << "<Date>" + date + "</Date>\n";		// ****************** TODO

		switch(type)
		{
		case TransactionType::deposit:
			{
			Deposit* deposit = dynamic_cast<Deposit*>(transaction);
			ss << deposit->getAmount(); // convert to string
			outFile << "<Amount>" + ss.str() + "</Amount>\n";
			ss.str(std::string()); // clear string stream
			outFile << "</Deposit>\n";
			}
			break;
		case TransactionType::loan:
			{
			Loan* loan = dynamic_cast<Loan*>(transaction);
			ss << loan->getAmount(); // convert to string
			outFile << "<Amount>" + ss.str() + "</Amount>\n";
			ss.str(std::string()); // clear string stream
			outFile << "</Loan>\n";
			}
			break;
		case TransactionType::query:
			outFile << "</BalanceCheck>\n";
			break;
		case TransactionType::transfer:
			{
			Transfer* transfer = dynamic_cast<Transfer*>(transaction);
			ss << transfer->getAmount(); // convert to string
			outFile << "<Amount>" + ss.str() + "</Amount>\n";
			ss.str(std::string()); // clear string stream

			ss << transfer->getTransferredTo(); // convert to string
			outFile << "<TransferredTo>" + ss.str() + "</TransferredTo>\n";
			ss.str(std::string()); // clear string stream
			outFile << "</Transfer>\n";
			}
			break;
		case TransactionType::withdraw:
			{
			Withdraw* withdraw = dynamic_cast<Withdraw*>(transaction);
			ss << withdraw->getAmount(); // convert to string
			outFile << "<Amount>" + ss.str() + "</Amount>\n";
			ss.str(std::string()); // clear string stream
			outFile << "</Withdraw>\n";
			}
			break;
		}
		it++;
	}
}


void TransactionManager::loadXml(std::ifstream & inFile)
{
	std::stack<std::string> s;
	std::string line;
	double id, accountNum, amount, to;
	Transaction* transaction;

	if(!std::getline(inFile, line))
		return;

	while(std::getline(inFile, line))
	{
		std::string type = line.substr(1, line.length()-2);
		s.push(line); // Transaction tag <Deposit>, <Withdraw>,...etc

		if(!std::getline(inFile, line))
			return;
		id = stod(XmlParseTag(line, "<TransactionID>", s));

		if(!std::getline(inFile, line))
			return;
		accountNum = stod(XmlParseTag(line, "<AccountNumber>", s));

		if(type == "Deposit")
		{
			if(!std::getline(inFile, line))
				return;
			amount = stod(XmlParseTag(line, "<Amount>", s));
			transaction = new Deposit(id, accountNum, amount);
		}
		else if(type == "Loan")
		{
			if(!std::getline(inFile, line))
				return;
			amount = stod(XmlParseTag(line, "<Amount>", s));
			transaction = new Loan(id, accountNum, amount);
		}
		else if(type == "BalanceCheck")
		{
			transaction = new CheckBalance(id, accountNum);
		}
		else if(type == "Transfer")
		{
			if(!std::getline(inFile, line))
				return;
			amount = stod(XmlParseTag(line, "<Amount>", s));
			if(!std::getline(inFile, line))
				return;
			to = stod(XmlParseTag(line, "<TransferredTo>", s));
			transaction = new Transfer(id, accountNum, amount, to);
		}
		else if(type == "Withdraw")
		{
			if(!std::getline(inFile, line))
				return;
			amount = stod(XmlParseTag(line, "<Amount>", s));
			transaction = new Withdraw(id, accountNum, amount);
		}
		history[id] = transaction;
		if(!std::getline(inFile, line))
			return;
		s.pop(); // pop transaction tag
	}
}

std::string TransactionManager::XmlParseTag(std::string & line, std::string TagName, std::stack<std::string> & s)
{
	std::string temp;
	s.push(TagName);
	line = line.substr(TagName.length(), line.length()-TagName.length()); //Ex.	number</AccountNumber>
	temp = line.substr(0, line.find("</"));
	line = line.substr(temp.length(), line.length()-temp.length());

	if(line.substr(2) != s.top().substr(1))
		return "";

	s.pop();
	return temp;
}

}
