#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node (int _val):val(_val),left(nullptr),right(nullptr){	}
};

class Tree{
	public:
		Tree();
		void add(int val);
		void find(int val);
		vector<vector<int>> levelOrderTrav1(Node *root);
		void preOrderTrav(Node* root);
		void inOrderTrav(Node* root);
		void postOrderTrav(Node* root);
		void levelOrderTrav();
		int height(Node*);
		Node *getRoot(); 
	private:
		Node* root;
};
Tree::Tree(){
	root = nullptr;
	cout << "tree root null" << endl;
}
void Tree::add(int val){
	//find the last node which has no left or right node
	if(!root){
		root = new Node(val);
		return;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()){
		Node *tmp = q.front();		
		q.pop();
		if (!tmp->left){
			tmp->left = new Node(val); 
			break;
		}			
		else if(!tmp->right){
			tmp->right = new Node(val);
			break;
		}
		if (tmp->left)
			q.push(tmp->left);
		if (tmp->right)
			q.push(tmp->right);		
	}
}
void Tree:: preOrderTrav(Node* root){
	if (root){
		cout << root->val << " ";
		preOrderTrav(root->left);
		preOrderTrav(root->right);
	}
}
Node* Tree::getRoot(){
	return root;
}
vector<vector<int>> Tree::levelOrderTrav1(Node* root){
	//关键：用一个栈记录跟踪node和该node所处的level
	//所以，当把所有的节点压入栈以后，各个Level的节点的信息自然就可以得到了 
	//所以，你就可以top-buttom 或者buttom-top打印了 
	vector<vector<int>> res;
	stack<pair<Node*, int>> sk;
	sk.push(make_pair(root, 0));
	Node *tmp;
	int level;
	while(!sk.empty()){		
		tmp = sk.top().first;		
		level = sk.top().second;
		sk.pop();
		if (tmp){
			if (res.size() <= level){
				res.push_back( vector<int>() );
			}			
			//cout << "(" << level << tmp->val << "), ";
			res[level].insert(res[level].begin(), tmp->val);
			sk.push(make_pair(tmp->left, level+1));
			sk.push(make_pair(tmp->right, level+1));
		}
	}
	return res;
}
int Tree::height(Node* root){
	if(!root)
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	int max = left>right?left:right;
	return max+1;
}
void showVec(vector<vector<int>> &v){
	cout << endl;
	for(int i = 0; i < v.size(); i++){
		cout << "level " << i << " has ";
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;			
	}
	cout << endl;
}

int main()
{
	Tree t;
	vector<int> v = {1,2,3,4,5};
	for (int i: v){
		t.add(i);
	}
	t.preOrderTrav(t.getRoot()); // 1 2 4 5 3
	vector<vector<int>> vv;
	vv = t.levelOrderTrav1(t.getRoot());//1 2 3 4 5 
	showVec(vv);
	cout << "height: " << t.height(t.getRoot()) << endl;
} 
