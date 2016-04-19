#ifndef __TREENODE__
#define __TREENODE__

template<class Type>
class TreeNode 
{
private:
	Type data; // different data type for other apps
	TreeNode<Type> *left; // a pointer to left child
	TreeNode<Type> *right; // a pointer to right child
public:
	TreeNode(Type x = 0, TreeNode<Type>* left = nullptr, TreeNode<Type>* right = nullptr);
	void setData(Type x);
	void setLeft(TreeNode<Type> *ptr);
	void setRight(TreeNode<Type> *ptr);
	Type getData();
	TreeNode<Type> * getLeft();
	TreeNode<Type> * getRight();
};

#endif // __TREENODE__