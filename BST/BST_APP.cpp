#include <iostream>
#include "BST.h"
#include <vector>
using namespace std;
int main()
{
	BST bt;
	vector<int> v = { 1, 2,0,4,9,6};
	for (int i = 0; i < v.size(); i++)
		bt.insertIter(v[i]);
	bt.inOrderRecur();
	/*
		BST bt1;
	vector<int> v1 = { 4, 2, 6, 1, 3, 5, 7 };
	for (int i = 0; i < v1.size(); i++)
		bt1.insertRecur(v1[i]);
	bt1.inOrderRecur();
	
	*/

}