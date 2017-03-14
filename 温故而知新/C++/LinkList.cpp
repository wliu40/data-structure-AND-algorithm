#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x = 0):data(x),next(NULL){}	
};

class LinkList{
	private:
		Node* head;
	public:
	LinkList(){
		head = nullptr;
	}
	LinkList(Node* _head){
		head = _head;
	}
	~LinkList(){
		delete head;
		cout << "deleting" << endl;
	}
	Node* getHead(){
		return head;
	}
	void addToHead(int val){
		if(head == NULL)
			head = new Node(val);
		else{
			Node *node = new Node(val);
			node->next = head;
			head = node;			
		}
	}
	bool isEmpty(){
		return head==NULL;
	}
	void show(){
		string s = "";
		Node* tmp = head;
		while(tmp != NULL){
			s += to_string(tmp->data);
			tmp = tmp->next;
		}
		cout << s << endl; 
	}
	void addToTail(int val){
		if(!head){
			head = new Node(val);
			return;
		}		
		Node* tmp = head;		
		while(tmp->next){
			tmp = tmp->next;			
		}
		tmp->next = new Node(val);
	}
	int sizeIter(){
		int size = 0;
		Node* tmp = head;
		while(tmp){
			tmp = tmp->next;
			size++;
		}
		return size;
	}
	int sizeRecurHelper(Node* node){
		if (!node)
			return 0;
		else
			return 1+sizeRecurHelper(node->next);
	}
	int sizeRecur(){
		return sizeRecurHelper(head);
	}
	
	void insertWithOrder(const vector<int> &v){
		for( int i : v){
			if(isEmpty() || i < head->data){
				addToHead(i);
			}
			else{
				Node *tmp = head;
				while(tmp->next && i > tmp->next->data){
					tmp = tmp->next;
				}
				
				if( !(tmp->next) )
				    tmp->next = new Node(i);
				else{
					Node* next = tmp->next;
					tmp->next = new Node(i);
					tmp->next->next = next;
				}
			}
		show();
		}
	}
	
};
Node* addTwoList(Node* l1, Node* l2){
		Node* ans = new Node();
		Node* tmp = new Node();
		ans = tmp;
		int carry = 0;
		int num1, num2; 
		while(l1 || l2 || carry){
			num1 = (l1)? l1->data:0;
			num2 = (l2)? l2->data:0;
			tmp->next = new Node((num1+num2+carry)%10);
			//cout << tmp->data << "! ";
			carry = (num1+num2+carry)/10;
			l1 = l1? l1->next:NULL;
			l2 = l2? l2->next:NULL; 
			tmp = tmp->next;			
		}
		return ans->next;
}
void foo(int &x){
	x = pow(x,2);
}
void foo2(vector<int> &v){
	for(auto it = v.begin(); it != v.end(); it++){
		(*it)++;
	}
}
int main()
{
	LinkList *l1 = new LinkList();
	vector<int> v = {1,2,3,6}; 
	for(int i:v){
		l1->addToHead(i);	
	} 
	l1->show();
	
	cout << l1->sizeIter() << endl;
	cout << l1->sizeRecur() << endl;
	
	vector<int> v2 = {8,9}; 
	LinkList *l2 = new LinkList();
	for(int i:v2){
		l2->addToTail(i);	
	} 
	l2->show();
	
	
	LinkList *l3 = new LinkList( addTwoList(l1->getHead(),l2->getHead()));
	l3->show();
	
	LinkList *l4 = new LinkList();
	l4->insertWithOrder(vector<int>{6,1,5,2,-5});
	l4->show();
	
	
	cout << endl << endl;
	int x = 10;
	int *px = &x;
	*px = 11;
	cout << "x = " << x << endl;
	foo(x);
	cout << "x = " << x << endl;	
	
	vector<int> v3 = {1,2,3};
	foo2(v3);
	for(int i:v3){
		cout << i << " ";
	}
	int arr[]= {0,0,1,5,};
	cout << arr << endl;
	int *parr = arr;
	cout << parr << endl;
	
	(*parr)++;
	cout << arr[0] << endl;
		
	
}
