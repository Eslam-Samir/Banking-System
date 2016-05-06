#include "Tree.h"

namespace BankingSystem
{

Tree::Tree(TreeNode* rootPtr)
{
	this->rootPtr = rootPtr;
}
TreeNode* Tree::getRoot()
{
	return rootPtr;
}

bool Tree::isEmpty()
{
	return rootPtr == nullptr;
}
Account* Tree::search(double x)
{
	if (isEmpty()) 
	{
		return nullptr;
	}
	TreeNode* p = rootPtr;
	while (p != nullptr)
	{
		Account tmp = *(p->getData());
		if (tmp.getAccountNumber() == x) 
			return p->getData();
		else if (x < tmp.getAccountNumber()) 
			p = p->getLeft();
		else 
			p = p->getRight();
	}
	return nullptr;
}

bool Tree::insert(Account* x)
{
	if (isEmpty()) 
	{
		rootPtr = new TreeNode(x);
		return true; 
	}
	TreeNode* p = rootPtr;
	while (p != nullptr)
	{
		Account a = *(p->getData());
		if (a.getAccountNumber() == x->getAccountNumber()) 
			return false; // account is already there
		else if (x->getAccountNumber() < a.getAccountNumber())
		{
			if (p->getLeft() == nullptr)
			{ 
				TreeNode* newNodePtr= new TreeNode(x);
				p->setLeft(newNodePtr); 
				return true;
			}
			else 
				p=p->getLeft();
		}
		else 
		{ 
			if (p->getRight() == nullptr)
			{ 
				TreeNode* newNodePtr= new TreeNode(x);
				p->setRight(newNodePtr); 
				return true;
			}
			else 
				p=p->getRight();
		}
	}
}
TreeNode* Tree::remove(Account* x)
{
	if (isEmpty()) 
		return nullptr;

	TreeNode* p = rootPtr;
	TreeNode* parent = nullptr; // parent of p
	char whatChild; // 'L' if p is a left child, 'R' Otherwise
	while (p != nullptr)
	{
		Account a = *(p->getData());
		if (a.getAccountNumber() == x->getAccountNumber()) break; // x found
		else if(x->getAccountNumber() < a.getAccountNumber()) 
		{ 
			parent = p; 
			whatChild = 'L';
			p = p->getLeft();
		}
		else  
		{
			parent = p; 
			whatChild = 'R';
			p = p->getRight();
		}
	}
	// Handle the case where p is a leaf.
	// Turn the appropriate pointer in its parent to nullptr
	if (p->getLeft() == nullptr && p->getRight() == nullptr)
	{
		if (parent != nullptr) // x is not at the root 
		{
			if (whatChild == 'L')
				parent->setLeft(nullptr);
			else
				parent->setRight(nullptr);
		}
		else // x is at the root
			rootPtr = nullptr;
		return p;
	}
	else if (p->getLeft() == nullptr)
	{
		// p has only one a child -- a right child. Let the parent of p
		// become an immediate parent of the right child of p.
		if (parent != nullptr) // p is not the root
		{
			if (whatChild == 'L') 
				parent->setLeft(p->getRight());
			else 
				parent->setRight(p->getRight());
		}
		else 
			rootPtr = p->getRight(); // p is the root
		return p;
	}
	else if (p->getRight() == nullptr)
	{
		// p has only one a child -- a left child. Let the parent of p
		// become an immediate parent of the left child of p.
		if (parent != nullptr) // p is not the root
		{
			if (whatChild == 'L') 
				parent->setLeft(p->getLeft());
			else 
				parent->setRight(p->getLeft());
		}
		else 
			rootPtr = p->getLeft(); // p is the root
		return p;
	}
	else { // p has two children
		TreeNode* returnNode= new TreeNode(*p); // replicates p
		TreeNode* leftChild = p->getLeft();
		if (leftChild->getRight() == nullptr)
		{// leftChild has no right child
			p->setData(leftChild->getData());
			p->setLeft(leftChild->getLeft());
			delete leftChild;
			return returnNode;
		}
		TreeNode* maxLeft = leftChild->getRight();
		TreeNode* parent2 = leftChild;
		while (maxLeft->getRight() != nullptr)
		{
			parent2 = maxLeft; 
			maxLeft = maxLeft ->getRight();
		}
		// now maxLeft is the node to swap with p.
		p->setData(maxLeft->getData());
		if (maxLeft->getLeft() == nullptr) 
			parent2->setRight(nullptr); // a leaf
		else 
			parent2->setRight(maxLeft->getLeft()); //not a leaf
		delete maxLeft;
		return returnNode;
	}
}

// Recursive function
void Tree::XmlNodeString(TreeNode* n, std::ofstream & outFile)
{
	if(n == nullptr)
		return;

	std::stringstream ss;
	Account * account = n->getData();
	outFile << "<Account>\n";
		ss << account->getAccountNumber(); // convert to string
		outFile << "<AccountNumber>" + ss.str() + "</AccountNumber>\n";
		ss.str(std::string()); // clear string stream

		ss << account->getBalance(); // convert to string
		outFile << "<Balance>" + ss.str() + "</Balance>\n";
		ss.str(std::string()); // clear string stream

		outFile << "<Password>" + account->getPassword() + "</Password>\n";
		//xmlStr += "<InterestRate>" + std::to_string(n->getData()->getInterestRate()) + "</InterestRate>"; // *********** TODO
		Client * client = account->getOwner();
		outFile << "<Client>\n";

			ss << client->getClientID(); // convert to string
			outFile << "<ClientID>" + ss.str() + "</ClientID>\n";
			ss.str(std::string()); // clear string stream

			outFile << "<Name>" + client->getName() + "</Name>\n";
			outFile << "<Address>" + client->getAddress() + "</Address>\n";
			outFile << "<DateOfBirth>" + client->getDateOfBirth() + "</DateOfBirth>\n";
			outFile << "<ClientAccounts>\n";
				std::vector<double> clientAccounts = client->getMyAccounts();
				for(int i = 0, size = clientAccounts.size(); i < size; i++)
				{
					ss << clientAccounts[i]; // convert to string
					outFile << "<ClientAccount>" + ss.str() + "</ClientAccount>\n";
					ss.str(std::string()); // clear string stream
				}
			outFile << "</ClientAccounts>\n";
		outFile << "</Client>\n";

		std::vector<double> transactions = account->getTransactionHistory();
		outFile << "<TransactionsCount>" + std::to_string(transactions.size()) + "</TransactionsCount>\n";
		if(transactions.size() > 0)
		{
			outFile << "<TransactionsHistory>\n";
				for(int i = 0, size = transactions.size(); i < size; i++)
				{
					ss << transactions[i]; // convert to string
					outFile << "<TransactionID>" + ss.str() + "</TransactionID>\n";
					ss.str(std::string()); // clear string stream
				}
			outFile << "</TransactionsHistory>\n";
		}

		if(!n->isLeaf())
		{
			XmlNodeString(n->getLeft(), outFile);
			XmlNodeString(n->getRight(), outFile);
		}

	outFile << "</Account>\n";
}

void Tree::XmlParseNode(std::ifstream & inFile, std::stack<std::string> & s)
{
	
	std::string line, accountNum, Balance, Password, Name, Address, DateOfBirth;
	double ClientID, transactionsCount;
	std::vector<double> clientAccounts;
	std::vector<double> transactions;

	if(!std::getline(inFile, line))
		return;
	accountNum = XmlParseTag(line, "<AccountNumber>", s);
	if(!std::getline(inFile, line))
		return;
	Balance = XmlParseTag(line, "<Balance>", s);
	if(!std::getline(inFile, line))
		return;
	Password = XmlParseTag(line, "<Password>", s);

	if(!std::getline(inFile, line))
		return;
	s.push(line); // <Client>

	if(!std::getline(inFile, line))
		return;
	ClientID = stod(XmlParseTag(line, "<ClientID>", s));
	if(!std::getline(inFile, line))
		return;
	Name = XmlParseTag(line, "<Name>", s);
	if(!std::getline(inFile, line))
		return;
	Address = XmlParseTag(line, "<Address>", s);
	if(!std::getline(inFile, line))
		return;
	DateOfBirth = XmlParseTag(line, "<DateOfBirth>", s);

	if(!std::getline(inFile, line))
		return;
	s.push(line); // <ClientAccounts>

	if(!std::getline(inFile, line))
		return;
	while(line.substr(2) != s.top().substr(1)) // while line != </ClientAccounts>
	{
		clientAccounts.push_back(stod(XmlParseTag(line, "<ClientAccount>", s)));
		if(!std::getline(inFile, line))
			return;
	}
	s.pop(); // pop </ClientAccounts>

	if(!std::getline(inFile, line) || line.substr(2) != s.top().substr(1))
		return;

	s.pop(); // pop </Client>

	Client* owner;
	bool clientExist = false;
	Account* acc=nullptr;
	for(int i = 0, size = clientAccounts.size(); i < size; i++)
	{
		if((acc = search(clientAccounts[i])) != nullptr)
		{
			clientExist = true;
			break;
		}
	}
	if(clientExist)
		owner = acc->getOwner();
	else
		owner = new Client(ClientID, Name, Address, DateOfBirth);

	if(!std::getline(inFile, line))
		return;
	transactionsCount = stod(XmlParseTag(line, "<TransactionsCount>", s));

	acc = new Account(stod(accountNum), stod(Balance), Password, owner);
	insert(acc);

	if(transactionsCount > 0)
	{
		if(!std::getline(inFile, line))
			return;
		s.push(line); // <TransactionsHistory>

		double transID;
		for(int i = 0; i < transactionsCount; i++)
		{
			if(!std::getline(inFile, line))
				return;
			transID = stod(XmlParseTag(line, "<TransactionID>", s));
			acc->addTransactionToHistory(transID);
		}

		if(!std::getline(inFile, line) || line.substr(2) != s.top().substr(1))
			return;

		s.pop(); // pop </TransactionsHistory>
	}


	while(line != "<Account>")
	{
		if(!std::getline(inFile, line))
			return;
		if(line.substr(2) == s.top().substr(1))
			s.pop();
		else if(line == "<Account>")
			s.push("<Account>");
	}
	if(s.empty())
		return;

	XmlParseNode(inFile, s);

}

std::string Tree::XmlParseTag(std::string & line, std::string TagName, std::stack<std::string> & s)
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

void Tree::createXml(std::ofstream & outFile)
{
	if(rootPtr == nullptr)
		return;
	XmlNodeString(rootPtr, outFile);
}

double Tree::loadXml(std::ifstream & inFile)
{
	std::stack<std::string> s;
	std::string line;
	std::getline(inFile, line);
	double numberOfAccounts = 0;
	if(!std::getline(inFile, line))
		return numberOfAccounts;

	numberOfAccounts = stod(XmlParseTag(line, "<NumberOfAccounts>", s));

	if(!std::getline(inFile, line))
		return numberOfAccounts;
	s.push(line); // <Account>
	XmlParseNode(inFile, s);
	return numberOfAccounts;
}

}