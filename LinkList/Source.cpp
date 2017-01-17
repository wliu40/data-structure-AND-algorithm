#include <iostream>
#include "LinkList.h"

using namespace std;

int main()
{
	LinkList lk;
	lk.addToTail(1);
	lk.addToTail(3);
	lk.addToTail(4);
	lk.addToTail(1);
	lk.addToTail(0);
	lk.show();
	cout << endl;

	int arr[] = { 2, 3, 6, 8, 3, 1 };
	LinkList lk1(arr, 6);
	lk1.show();
}