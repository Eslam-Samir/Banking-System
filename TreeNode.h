#ifndef __TREENODE__
#define __TREENODE__

#include "Account.h"

class TreeNode 
{
private:
	Account* account; // different data type for other apps
	TreeNode* left; // a pointer to left child
	TreeNode* right; // a pointer to right child
public:
	TreeNode(Account* x = nullptr, TreeNode* left = nullptr, TreeNode* right = nullptr);
	void setData(Account* x);
	void setLeft(TreeNode *ptr);
	void setRight(TreeNode *ptr);
	Account* getData();
	TreeNode* getLeft();
	TreeNode* getRight();

	bool isLeaf();
};


#endif // __TREENODE__