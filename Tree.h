#ifndef __TREE__
#define __TREE__

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

#include "TreeNode.h"

namespace BankingSystem
{

class Tree
{
private:
	TreeNode* rootPtr;
	void XmlNodeString(TreeNode* n, std::ofstream & outFile);
	void XmlParseNode(std::ifstream & inFile, std::stack<std::string> & s);
	std::string XmlParseTag(std::string & line, std::string TagName, std::stack<std::string> & s);

public:
	Tree(TreeNode* rootPtr = nullptr);
	TreeNode* getRoot();
	bool isEmpty();

	Account* search(double x);
	bool insert(Account* x);
	TreeNode* remove(Account* x);

	void createAccountsXml(std::ofstream & outFile);
	double loadAccountsXml(std::ifstream & inFile);
};

}

#endif // __TREE__