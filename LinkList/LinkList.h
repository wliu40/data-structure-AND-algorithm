#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class LinkList
{
public:
	LinkList();
	LinkList(const int*, int size);//��һ��array����һ��LinkList
	~LinkList();
	void addToTail(int x);
	void show();
	bool isEmpty();
private:
	typedef struct _Node
	{
		int data;
		_Node* next;
		_Node() :data(0), next(nullptr){}//structҲ�й��캯������
		_Node(int inputData) :data(inputData), next(nullptr){}//struct����һ�����캯��
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

