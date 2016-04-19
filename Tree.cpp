#include "Tree.h"


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
