#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x = 0):val(x),next(NULL){}
};
class LinkList{
	public:
	ListNode *head;
	LinkList(){
		head = NULL;
	}
	void add(int val){
		if (!head){
			head = new ListNode(val);
		}
		else{
			ListNode *tmp = head;
			while(tmp->next){
				tmp = tmp->next;
			}
			tmp->next = new ListNode(val);
		}		
	}
	void show(){
		string s = "";
		ListNode *tmp = head;
		while (tmp){
			s += to_string(tmp->val) + " ";
			tmp = tmp->next;
		}
		cout << s << endl;
	}

};

ListNode* sortList(ListNode* head) {
        if (!head || !head->next) 
            return head;
        cout << "!!" << endl; 
        ListNode *fast(head);
        ListNode *slow = new ListNode(0);
        slow->next = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);
        cout << left->val << "," << right->val << endl; 
        ListNode *dummy_k = new ListNode(0);
        ListNode *i(left), *j(right), *k(dummy_k);
        while (i && j){
            if(i->val < j->val){
                k->next = new ListNode(i->val);
                i = i->next;
            }
            else{
                k->next = new ListNode(j->val);
                j = j->next;
            }
            k = k->next;
        }
        while(i){
            k->next = new ListNode(i->val);
            i = i->next; k = k->next;
        }
        while(j){
            k->next = new ListNode(j->val);
            j = j->next; k = k->next;
        }
        return dummy_k->next;
    }

int main(){
	LinkList lk;
	vector<int> v = {1,0,5,3};
	for(int i: v){
		lk.add(i);
	} 
	lk.show();
	lk.head = sortList(lk.head);	
	lk.show();
	
}
