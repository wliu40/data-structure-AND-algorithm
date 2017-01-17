#pragma once
#include <iostream>
using namespace std;

struct Node //struct与类的区别： struct的成员默认是public，而class默认Private,其他相同
{
	int value;
	Node* left;
	Node* right;
	Node(int _value)//struct的构造函数
	{
		value = _value;
		left = NULL;
		right = NULL;
	}
};

class BiTree
{

public:
	BiTree();
	~BiTree();

	//递归建树 
	void insert_recursive(int x);
	Node* insert_recursive(Node*, int);

	//非递归建树 
	void create_tree(int *arr, int arr_size);
	void add_node(int val);

	//中序，先序，后序，递归法遍历 
	void InOrderTraversal(Node* _root);
	void PreOrderTraversal(Node* _root);
	void PostOrderTraversal(Node* _root);

	//中序，先序，后序，非递归法遍历 
	void InOrderTraversal_NoRecursive(Node* _root);
	void PreOrderTraversal_NoRecursive(Node* _root);
	void PreOrderTraversal_NoRecursive_1(Node* _root);
	void PostOrderTraversal_NoRecursive(Node* _root);

	//层次遍历 
	void LevelOrderTraversal(Node* _root);

	//搜索某节点 
	string search_node(int val);

	//返回树的高度 
	int get_height(Node* _root);

	//返回根节点
	Node* get_root();
private:
	Node* root;

};

