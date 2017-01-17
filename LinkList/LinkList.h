#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class LinkList
{
public:
	LinkList();
	LinkList(const int*, int size);//由一个array构建一个LinkList
	~LinkList();
	void addToTail(int x);
	void show();
	bool isEmpty();
private:
	typedef struct _Node
	{
		int data;
		_Node* next;
		_Node() :data(0), next(nullptr){}//struct也有构造函数啊！
		_Node(int inputData) :data(inputData), next(nullptr){}//struct的另一个构造函数
		~_Node()
		{
			delete next;
			cout << "inside the node" << endl;
		}
	} Node;
	Node *head;
	Node *tail;
	int size;
};

