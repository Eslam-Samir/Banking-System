#include "TreeNode.h"

namespace BankingSystem
{

TreeNode::TreeNode(Account* x, TreeNode* left, TreeNode* right)
{
	account = x; 
	this->left = left; 
	this->right = right; 
}
void TreeNode::setData(Account* x) 
{
	account = x;
}

void TreeNode::setLeft(TreeNode* ptr) 
{
	left = ptr;
}

void TreeNode::setRight(TreeNode* ptr) 
{
	right = ptr;
}

Account* TreeNode::getData() 
{
	return account;
}

TreeNode* TreeNode::getLeft() 
{
	return left;
}

TreeNode* TreeNode::getRight() 
{
	return right;
}

bool TreeNode::isLeaf()
{
	if(getRight() == nullptr && getLeft() == nullptr)
		return true;
	else
		return false;
}

}