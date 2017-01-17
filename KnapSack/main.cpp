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
	cout << "������" << v1.size() << "����Ʒ�� ������Ʒ������Ϊ1�� 2�� 3�� ��ֵΪ6, 10, 12" << endl << endl;
	ks1.solver_0_1();
	cout << "���ľ����ǣ�" << endl;
	ks1.showMatrix();
	cout << "�����½ǵ�Ԫ�ؼ�������Ľ�" << endl << endl;

}