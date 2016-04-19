#ifndef __TREE__
#define __TREE__

#include "TreeNode.h"

class Tree
{
private:
	TreeNode* rootPtr;

public:
	Tree(TreeNode* rootPtr = nullptr);
	TreeNode* getRoot();
	bool isEmpty();

	Account* search(double x);
	bool insert(Account* x);
	TreeNode* remove(Account* x);
};


#endif // __TREE__