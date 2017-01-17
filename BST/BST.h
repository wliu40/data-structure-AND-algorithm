#pragma once
#ifndef _BST_H
#define _BST_H

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
	TreeNode() :val(0), left(nullptr), right(nullptr){}
	~TreeNode(){
		if (left)
			delete left;
		if (right)
			delete right;
	}
};

class BST
{
public:
	BST();
	~BST();
	void insertIter(int x);
	void insertRecur(int x);

	bool isEmpty(){
		return root == nullptr;
	}
	void preOrderIter();
	void preOrderRecur();
	void inOrderIter();
	void inOrderRecur();
	void postOrderIter();
	void postOrderRecur();
	void height();
	void byLevel();
	void isSymmetric();
	void isSameTree(BST* that);
	int pathSum();
	void sideView();

private:
	void insertRecur(TreeNode*, int);
	void inOrderRecur(TreeNode* _root);
//	int height;
	TreeNode *root;

};

#endif