#include "TreeNode.h"

template<class Type>
TreeNode<Type>::TreeNode(Type x, TreeNode<Type>* left, TreeNode<Type>* right)
{
	data=x; 
	this->left=left; 
	this->right=right; 
}
template<class Type>
void TreeNode<Type>::setData(Type x) 
{
	data = x;
}
template<class Type>
void TreeNode<Type>::setLeft(TreeNode<Type> *ptr) 
{
	left = ptr;
}
template<class Type>
void TreeNode<Type>::setRight(TreeNode<Type> *ptr) 
{
	right = ptr;
}
template<class Type>
Type TreeNode<Type>::getData() 
{
	return data;
}
template<class Type>
TreeNode<Type>* TreeNode<Type>::getLeft() 
{
	return left;
}
template<class Type>
TreeNode<Type>* TreeNode<Type>::getRight() 
{
	return right;
}