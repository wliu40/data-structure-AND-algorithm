#pragma once
#include <iostream>
using namespace std;

struct Node //struct��������� struct�ĳ�ԱĬ����public����classĬ��Private,������ͬ
{
	int value;
	Node* left;
	Node* right;
	Node(int _value)//struct�Ĺ��캯��
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

	//�ݹ齨�� 
	void insert_recursive(int x);
	Node* insert_recursive(Node*, int);

	//�ǵݹ齨�� 
	void create_tree(int *arr, int arr_size);
	void add_node(int val);

	//�������򣬺��򣬵ݹ鷨���� 
	void InOrderTraversal(Node* _root);
	void PreOrderTraversal(Node* _root);
	void PostOrderTraversal(Node* _root);

	//�������򣬺��򣬷ǵݹ鷨���� 
	void InOrderTraversal_NoRecursive(Node* _root);
	void PreOrderTraversal_NoRecursive(Node* _root);
	void PreOrderTraversal_NoRecursive_1(Node* _root);
	void PostOrderTraversal_NoRecursive(Node* _root);

	//��α��� 
	void LevelOrderTraversal(Node* _root);

	//����ĳ�ڵ� 
	string search_node(int val);

	//�������ĸ߶� 
	int get_height(Node* _root);

	//���ظ��ڵ�
	Node* get_root();
private:
	Node* root;

};

