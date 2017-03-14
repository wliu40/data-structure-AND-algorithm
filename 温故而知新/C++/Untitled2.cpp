// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int _val = 0):val(_val),next(NULL){}	
};

int main () {
	Node n(5);
	cout << n.val << endl;//5
	
	Node nn(n);
	n.val = 4;
	cout << nn.val << endl;//5
	
	Node *np = new Node(1);
	Node *np1(np);
	np->val = 2;
	cout << np1->val << endl;//2
	cout << "np = "<< np << "; np1 = " << np1 << endl;//they are the same
	cout << "&np = "<< &np << "; &np1 = " << &np1 << endl;//they are not the same	
	
		
	Node *np2;
	np2 = np1;
	cout << np2->val << endl;
	
	np->val = 3;
	cout << np2->val << endl;//3
	
	
	 
	
}
