#include <iostream>
#include <string>
#include "BiTree.h"
using namespace std;

int main()
{
	//	int array[] = {8,3,1,6,4,7,10,14,13,-1,2, 0};
	int array[] = { 4, 5, 2, 6, 3, 9, 0, 1 };
	int len = sizeof(array) / sizeof(int);
	BiTree *bt = new BiTree();

	//	bt->create_tree(array, len); //��ȡһ������������BST���ǵݹ鷽�� 

	//�ݹ齨���� 
	for (int i = 0; i < len; i++)
	{
		bt->insert_recursive(array[i]);
		cout << array[i];
	}

	cout << "\nInOrderTraversal(�������): " << endl;
	bt->InOrderTraversal(bt->get_root());

	cout << "\nPreOrderTraversal(�������): " << endl;
	bt->PreOrderTraversal(bt->get_root());

	cout << "\nPostOrderTraversal(�������): " << endl;
	bt->PostOrderTraversal(bt->get_root());

	cout << "\nLevelOrderTraversal(��α���): " << endl;
	bt->LevelOrderTraversal(bt->get_root());

	cout << "\n�ǵݹ��������: " << endl;
	bt->InOrderTraversal_NoRecursive(bt->get_root());

	cout << "\n�ǵݹ��������: " << endl;
	bt->PreOrderTraversal_NoRecursive(bt->get_root());

	cout << "\n�ǵݹ��������(��һ�ַ���): " << endl;
	bt->PreOrderTraversal_NoRecursive_1(bt->get_root());

	cout << "\n�ǵݹ�������: " << endl;
	bt->PostOrderTraversal_NoRecursive(bt->get_root());

	cout << "\n���ĸ߶�: " << endl;
	cout << bt->get_height(bt->get_root()) << endl;
	//	cout << bt->search_node(-1) << endl;

	string num;
	int number;
	while (1)
	{
		cout << "\n����Ҫ��ѯ������(q�˳�)�� ";
		cin >> num;
		if (num == "q")
			break;
		else
		{
			number = atoi(num.c_str());
			cout << bt->search_node(number) << endl;
		}
	}

	delete bt;
	return 0;
}