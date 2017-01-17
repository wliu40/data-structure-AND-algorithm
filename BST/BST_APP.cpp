#include <iostream>
#include "BST.h"
#include <vector>
using namespace std;
int main()
{
	BST bt;
	vector<int> v = { 4, 2, 6, 1, 3, 5, 7 };
	for (int i = 0; i < v.size(); i++)
		bt.insertIter(v[i]);
	bt.inOrderRecur();
}