#ifndef __TREE__
#define __TREE__

#include "TreeNode.h"
#include <string>
#include <vector>
#include <sstream>

class Tree
{
private:
	TreeNode* rootPtr;
	std::string XmlNodeString(TreeNode* n);

public:
	Tree(TreeNode* rootPtr = nullptr);
	TreeNode* getRoot();
	bool isEmpty();

	Account* search(double x);
	bool insert(Account* x);
	TreeNode* remove(Account* x);

	std::string createXml();
};


#endif // __TREE__