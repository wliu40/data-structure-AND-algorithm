#include "BiTree.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

BiTree::BiTree()
{
	root = NULL;
}


BiTree::~BiTree()
{
}



void BiTree::create_tree(int* arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		add_node(arr[i]);
	}
}
//增加一个二叉搜索树的节点 
void BiTree::add_node(int val)
{
	//把int型数据放入一个新节点，该节点最终将插入树 
	Node* n = new Node(val);
	if (root == NULL)
	{
		root = n;//第一个输入的数据就是树的根 
	}
	else
	{
		//建造一个临时节点，代表现在正在操作的节点
		//临时节点从根节点开始 
		Node* current_node = root;
		while (1)//条件一直为真，直到新节点找到自己的合适插入位置后跳出循环 
		{
			//如果新节点的数据比现在临时节点的数据小 
			if (val < current_node->value)
			{
				//如果临时节点有左节点，那么就要再跟左节点比大小
				//临时节点赋值为左节点 
				if (current_node->left)
					current_node = current_node->left;
				else//如果临时节点没有左节点，那么新节点就是左节点，
					//赋值并跳出循环 
				{
					current_node->left = n;
					break;
				}

			}
			else //如果新节点的数据比现在临时节点要大 
			{  //如果临时节点有右节点，那么就要再跟右节点比大小
				//临时节点赋值刷新为右节点 
				if (current_node->right)
					current_node = current_node->right;
				else//如果没有右节点，则新节点成为右节点，
					//完成赋值并跳出循环 
				{
					current_node->right = n;
					break;
				}

			}
		}

	}

}
//中序遍历 ，递归方法 
void BiTree::InOrderTraversal(Node* _root)
{
	if (_root)
	{
		InOrderTraversal(_root->left);
		cout << _root->value << " ";
		InOrderTraversal(_root->right);
	}

}
//先序遍历 ，递归方法 
void BiTree::PreOrderTraversal(Node* _root)
{
	if (_root)
	{
		cout << _root->value << " ";
		PreOrderTraversal(_root->left);
		PreOrderTraversal(_root->right);
	}

}
//后序遍历 ，递归方法 
void BiTree::PostOrderTraversal(Node* _root)
{
	if (_root)
	{
		PostOrderTraversal(_root->left);
		PostOrderTraversal(_root->right);
		cout << _root->value << " ";
	}

}
//返回数的根节点 
Node* BiTree::get_root()
{
	return root;
}
//层次遍历，其实就是广度搜索。
//使用一个队列，在循环外，首先把根节点压入队列。
//在循环内，首先弹出队列的最前面元素，并访问之。 
//弹出后，把该元素的左儿子，右儿子压入队列。
//循环继续，直到队列为空时，循环结束。 
void BiTree::LevelOrderTraversal(Node* _root)
{
	if (_root == NULL)
	{
		return;
	}
	queue <Node*> myque;
	myque.push(_root);

	while (!myque.empty())
	{
		Node *n = myque.front();
		myque.pop();
		cout << n->value << " ";
		if (n->left)
			myque.push(n->left);
		if (n->right)
			myque.push(n->right);
	}
}
//中序遍历，非递归方法 
//非递归方法使用一个栈，来模拟递归的函数。 
void BiTree::InOrderTraversal_NoRecursive(Node* _root)
{
	Node* n = _root; //设置临时变量，从根节点开始遍历 
	stack <Node*> sk;//一个储存Node指针型变量的stack 

	while (n || !sk.empty())//当stack不空时 
	{
		while (n)//从临时变量开始，找到其所有的左儿子，左孙子，左重孙...压入栈
			//直到左边的“路”走完（左后代为null） 
		{
			sk.push(n);
			cout << "push(" << n->value << ") ";
			n = n->left;
		}
		cout << endl;
		n = sk.top();//n重新赋值为栈顶元素 
		//	cout << n->value << " ";
		cout << "pop(" << n->value << ") "; //弹出栈顶元素并访问之 
		sk.pop();
		n = n->right;//n重新赋值为刚访问的元素的右儿子 
		//	cout << endl;
	}
}
//先序遍历，非递归方法 
//与上面的中序遍历是及其形似的，只是访问的时机不一样 
void BiTree::PreOrderTraversal_NoRecursive(Node* _root)
{
	Node* n = _root;
	stack <Node*> sk;
	if (_root == NULL)
		return;
	while (n || !sk.empty())
	{
		while (n)
		{
			cout << n->value << " ";//访问时机的不同 
			sk.push(n);
			n = n->left;
		}
		n = sk.top();
		sk.pop();
		n = n->right;
	}

}
//先序遍历，非递归方法的另一种实现 
void BiTree::PreOrderTraversal_NoRecursive_1(Node* _root)
{
	Node* n = _root;
	if (_root == NULL)
		return;
	stack <Node*> sk;
	sk.push(n);
	cout << "建立栈，压入根节点." << endl;

	while (!sk.empty())
	{
		//每次弹出一个栈顶元素，并访问之。 
		n = sk.top();
		cout << "弹出" << n->value << "并访问之. ";
		cout << n->value << " ";
		sk.pop();
		//如果该节点有右儿子的话就压入栈 
		if (n->right){
			cout << "压入" << n->right->value << ", ";
			sk.push(n->right);
		}
		//如果该节点有左儿子的话就压入栈
		if (n->left){
			cout << "压入" << n->left->value << ". ";
			sk.push(n->left);
		}

		cout << endl;

	}

}
//后序遍历，非递归方法 
void BiTree::PostOrderTraversal_NoRecursive(Node* _root)
{
	Node *n = _root;
	if (!n)
		return;
	stack <Node*> sk, out;
	sk.push(n);
	cout << "压根节点入栈A." << endl;
	while (!sk.empty())
	{
		n = sk.top();
		cout << "把" << n->value << "压入栈B, ";
		out.push(n);
		cout << "把" << n->value << "从栈A弹出, ";
		sk.pop();

		if (n->left)
		{
			cout << "把左儿子" << n->left->value << "压入栈A, ";
			sk.push(n->left);
		}

		if (n->right)
		{
			cout << "把右儿子" << n->right->value << "压入栈A, ";
			sk.push(n->right);
		}

		cout << endl;

	}
	cout << "下面开始操作栈B: " << endl;
	while (!out.empty())
	{
		n = out.top();
		cout << "访问栈顶元素" << n->value << "并弹出；\n";
		//	cout << n->value << " ";
		out.pop();
	}
}
//在二叉搜索树中查找某个值 
string BiTree::search_node(int val)
{
	if (root == NULL)
		return "root = NULL";
	Node* n = root;
	while (n)
	{
		if (n->value == val)
			return "found";
		if (val < n->value)
			n = n->left;
		else
		{
			n = n->right;
		}
	}
	return "not found";

}
//返回二叉树的高度（递归实现）
int BiTree::get_height(Node *_root)
{
	int left_height, right_height, max_height;
	if (!_root)
		return 0;
	else
	{
		left_height = get_height(_root->left);
		right_height = get_height(_root->right);
		max_height = (left_height > right_height) ? left_height : right_height;
		max_height++;
		return max_height;
	}

}
//建树的递归实现（其实跟非递归也没啥太大区别） 
void BiTree::insert_recursive(int x)
{
	if (root == NULL)
		root = new Node(x);
	else
		insert_recursive(root, x);
}
Node* BiTree::insert_recursive(Node* _root, int x)
{
	if (_root == NULL)
		_root = new Node(x);
	else
	{
		if (x < _root->value)
			_root->left = insert_recursive(_root->left, x);
		else
			_root->right = insert_recursive(_root->right, x);
	}
	return _root;
	//	if (x < _root->value)
	//	{	
	//		if (_root->left)
	//		{
	//			insert_recursive(_root->left, x);
	//		}
	//		else
	//		{
	//			_root->left = new Node(x);		 
	//		}
	//	}
	//	else
	//	{
	//		if (_root->right )
	//		{
	//			insert_recursive(_root->right, x);
	//		}
	//		else
	//		{
	//			_root->right=new Node(x);			
	//		}
	//	}

}
