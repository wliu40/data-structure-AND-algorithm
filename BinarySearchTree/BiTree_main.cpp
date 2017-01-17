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

	//	bt->create_tree(array, len); //读取一个数组来创建BST，非递归方法 

	//递归建树法 
	for (int i = 0; i < len; i++)
	{
		bt->insert_recursive(array[i]);
		cout << array[i];
	}

	cout << "\nInOrderTraversal(中序遍历): " << endl;
	bt->InOrderTraversal(bt->get_root());

	cout << "\nPreOrderTraversal(先序遍历): " << endl;
	bt->PreOrderTraversal(bt->get_root());

	cout << "\nPostOrderTraversal(后序遍历): " << endl;
	bt->PostOrderTraversal(bt->get_root());

	cout << "\nLevelOrderTraversal(层次遍历): " << endl;
	bt->LevelOrderTraversal(bt->get_root());

	cout << "\n非递归中序遍历: " << endl;
	bt->InOrderTraversal_NoRecursive(bt->get_root());

	cout << "\n非递归先序遍历: " << endl;
	bt->PreOrderTraversal_NoRecursive(bt->get_root());

	cout << "\n非递归先序遍历(另一种方法): " << endl;
	bt->PreOrderTraversal_NoRecursive_1(bt->get_root());

	cout << "\n非递归后序遍历: " << endl;
	bt->PostOrderTraversal_NoRecursive(bt->get_root());

	cout << "\n树的高度: " << endl;
	cout << bt->get_height(bt->get_root()) << endl;
	//	cout << bt->search_node(-1) << endl;

	string num;
	int number;
	while (1)
	{
		cout << "\n输入要查询的数字(q退出)： ";
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