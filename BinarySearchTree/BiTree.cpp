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
//����һ�������������Ľڵ� 
void BiTree::add_node(int val)
{
	//��int�����ݷ���һ���½ڵ㣬�ýڵ����ս������� 
	Node* n = new Node(val);
	if (root == NULL)
	{
		root = n;//��һ����������ݾ������ĸ� 
	}
	else
	{
		//����һ����ʱ�ڵ㣬�����������ڲ����Ľڵ�
		//��ʱ�ڵ�Ӹ��ڵ㿪ʼ 
		Node* current_node = root;
		while (1)//����һֱΪ�棬ֱ���½ڵ��ҵ��Լ��ĺ��ʲ���λ�ú�����ѭ�� 
		{
			//����½ڵ�����ݱ�������ʱ�ڵ������С 
			if (val < current_node->value)
			{
				//�����ʱ�ڵ�����ڵ㣬��ô��Ҫ�ٸ���ڵ�ȴ�С
				//��ʱ�ڵ㸳ֵΪ��ڵ� 
				if (current_node->left)
					current_node = current_node->left;
				else//�����ʱ�ڵ�û����ڵ㣬��ô�½ڵ������ڵ㣬
					//��ֵ������ѭ�� 
				{
					current_node->left = n;
					break;
				}

			}
			else //����½ڵ�����ݱ�������ʱ�ڵ�Ҫ�� 
			{  //�����ʱ�ڵ����ҽڵ㣬��ô��Ҫ�ٸ��ҽڵ�ȴ�С
				//��ʱ�ڵ㸳ֵˢ��Ϊ�ҽڵ� 
				if (current_node->right)
					current_node = current_node->right;
				else//���û���ҽڵ㣬���½ڵ��Ϊ�ҽڵ㣬
					//��ɸ�ֵ������ѭ�� 
				{
					current_node->right = n;
					break;
				}

			}
		}

	}

}
//������� ���ݹ鷽�� 
void BiTree::InOrderTraversal(Node* _root)
{
	if (_root)
	{
		InOrderTraversal(_root->left);
		cout << _root->value << " ";
		InOrderTraversal(_root->right);
	}

}
//������� ���ݹ鷽�� 
void BiTree::PreOrderTraversal(Node* _root)
{
	if (_root)
	{
		cout << _root->value << " ";
		PreOrderTraversal(_root->left);
		PreOrderTraversal(_root->right);
	}

}
//������� ���ݹ鷽�� 
void BiTree::PostOrderTraversal(Node* _root)
{
	if (_root)
	{
		PostOrderTraversal(_root->left);
		PostOrderTraversal(_root->right);
		cout << _root->value << " ";
	}

}
//�������ĸ��ڵ� 
Node* BiTree::get_root()
{
	return root;
}
//��α�������ʵ���ǹ��������
//ʹ��һ�����У���ѭ���⣬���ȰѸ��ڵ�ѹ����С�
//��ѭ���ڣ����ȵ������е���ǰ��Ԫ�أ�������֮�� 
//�����󣬰Ѹ�Ԫ�ص�����ӣ��Ҷ���ѹ����С�
//ѭ��������ֱ������Ϊ��ʱ��ѭ�������� 
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
//����������ǵݹ鷽�� 
//�ǵݹ鷽��ʹ��һ��ջ����ģ��ݹ�ĺ����� 
void BiTree::InOrderTraversal_NoRecursive(Node* _root)
{
	Node* n = _root; //������ʱ�������Ӹ��ڵ㿪ʼ���� 
	stack <Node*> sk;//һ������Nodeָ���ͱ�����stack 

	while (n || !sk.empty())//��stack����ʱ 
	{
		while (n)//����ʱ������ʼ���ҵ������е�����ӣ������ӣ�������...ѹ��ջ
			//ֱ����ߵġ�·�����꣨����Ϊnull�� 
		{
			sk.push(n);
			cout << "push(" << n->value << ") ";
			n = n->left;
		}
		cout << endl;
		n = sk.top();//n���¸�ֵΪջ��Ԫ�� 
		//	cout << n->value << " ";
		cout << "pop(" << n->value << ") "; //����ջ��Ԫ�ز�����֮ 
		sk.pop();
		n = n->right;//n���¸�ֵΪ�շ��ʵ�Ԫ�ص��Ҷ��� 
		//	cout << endl;
	}
}
//����������ǵݹ鷽�� 
//���������������Ǽ������Ƶģ�ֻ�Ƿ��ʵ�ʱ����һ�� 
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
			cout << n->value << " ";//����ʱ���Ĳ�ͬ 
			sk.push(n);
			n = n->left;
		}
		n = sk.top();
		sk.pop();
		n = n->right;
	}

}
//����������ǵݹ鷽������һ��ʵ�� 
void BiTree::PreOrderTraversal_NoRecursive_1(Node* _root)
{
	Node* n = _root;
	if (_root == NULL)
		return;
	stack <Node*> sk;
	sk.push(n);
	cout << "����ջ��ѹ����ڵ�." << endl;

	while (!sk.empty())
	{
		//ÿ�ε���һ��ջ��Ԫ�أ�������֮�� 
		n = sk.top();
		cout << "����" << n->value << "������֮. ";
		cout << n->value << " ";
		sk.pop();
		//����ýڵ����Ҷ��ӵĻ���ѹ��ջ 
		if (n->right){
			cout << "ѹ��" << n->right->value << ", ";
			sk.push(n->right);
		}
		//����ýڵ�������ӵĻ���ѹ��ջ
		if (n->left){
			cout << "ѹ��" << n->left->value << ". ";
			sk.push(n->left);
		}

		cout << endl;

	}

}
//����������ǵݹ鷽�� 
void BiTree::PostOrderTraversal_NoRecursive(Node* _root)
{
	Node *n = _root;
	if (!n)
		return;
	stack <Node*> sk, out;
	sk.push(n);
	cout << "ѹ���ڵ���ջA." << endl;
	while (!sk.empty())
	{
		n = sk.top();
		cout << "��" << n->value << "ѹ��ջB, ";
		out.push(n);
		cout << "��" << n->value << "��ջA����, ";
		sk.pop();

		if (n->left)
		{
			cout << "�������" << n->left->value << "ѹ��ջA, ";
			sk.push(n->left);
		}

		if (n->right)
		{
			cout << "���Ҷ���" << n->right->value << "ѹ��ջA, ";
			sk.push(n->right);
		}

		cout << endl;

	}
	cout << "���濪ʼ����ջB: " << endl;
	while (!out.empty())
	{
		n = out.top();
		cout << "����ջ��Ԫ��" << n->value << "��������\n";
		//	cout << n->value << " ";
		out.pop();
	}
}
//�ڶ����������в���ĳ��ֵ 
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
//���ض������ĸ߶ȣ��ݹ�ʵ�֣�
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
//�����ĵݹ�ʵ�֣���ʵ���ǵݹ�Ҳûɶ̫������ 
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
