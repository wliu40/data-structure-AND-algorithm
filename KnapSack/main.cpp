#include <iostream>
#include "Item.h"
#include "KnapSack.h"

using namespace std;

int main()
{
	vector<Item> v;
	v.push_back(Item(1, 6, 30));
	v.push_back(Item(2, 3, 14));
	v.push_back(Item(3, 4, 16));
	v.push_back(Item(4, 2, 9));
	v.push_back(Item(5, 10, 199));

	KnapSack ks(v, 10);
	ks.solver_repetation();
	ks.showItemsInSack();

	cout << "===================================================" << endl;
	ks.solver_repetation_1();
	ks.showItemsInSack();
	cout << endl;

	vector<Item> v1;
	v1.push_back(Item(1, 1, 6));
	v1.push_back(Item(2, 2, 10));
	v1.push_back(Item(3, 3, 12));
	KnapSack ks1(v1, 5);
	cout << "现在有" << v1.size() << "个物品， 各个物品的重量为1， 2， 3， 价值为6, 10, 12" << endl << endl;
	ks1.solver_0_1();
	cout << "最后的矩阵是：" << endl;
	ks1.showMatrix();
	cout << "最右下角的元素即是问题的解" << endl << endl;

}