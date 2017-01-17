#include "BST.h"
#include <iostream>
using std::cout;
using std::endl;

BST::BST()
{
	root = nullptr;
//	height = 0;
}

BST::~BST()
{

}
void BST::insertRecur(int x)
{
	insertRecur(root, x);
}
void BST::insertRecur(TreeNode* _root, int x)
{
	if (!_root)
		_root = new TreeNode(x);
	else
	{
		if (x < _root->val)
			insertRecur(_root->left, x);
		else
			insertRecur(_root->right, x);
	}
}
void BST::insertIter(int x)
{
	if (isEmpty())
		root = new TreeNode(x);
	else
	{
		TreeNode *cur = root;
		while (1)
		{
			if (x < cur->val)
			{
				if (cur->left)
					cur = cur->left;
				else
				{
					cur->left = new TreeNode(x);
					break;
				}
			}
			else
			{
				if (cur->right)
				{
					cur = cur->right;
				}
				else
				{
					cur->right = new TreeNode(x);
					break;
				}
			}			
		}
	}
}
void BST::inOrderRecur()
{
	inOrderRecur(root);
}
void BST::inOrderRecur(TreeNode *_root)
{
	if (_root){
		cout << _root->val << " ";
		inOrderRecur(_root->left);
		inOrderRecur(_root->right);
	}
}