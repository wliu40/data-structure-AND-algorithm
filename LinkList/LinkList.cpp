#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::LinkList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

LinkList::LinkList(const int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		addToTail(arr[i]);
	}

}
LinkList::~LinkList()
{

}
bool LinkList::isEmpty()
{
	return head == nullptr;
}
void LinkList::addToTail(int num)
{
	Node *pNode = new Node(num); //无论如何，先得创建一个新的Node
	if (isEmpty())
	{
		head = pNode;
		tail = pNode;
		size++;
	}
	else
	{
		tail->next = pNode;
		tail = pNode;
		size++;
	}

}
////////////////////////////////////////////////////////
void LinkList::show()
{
	Node *cur = head;
	while (cur != nullptr)
	{
		cout << cur->data << ", ";
		cur = cur->next;
	}
	//delete cur;
}
