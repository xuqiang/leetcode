#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

 void deleteNode(ListNode* node) {
        if(node->next == NULL) return ;
        node->val = node->next->val;
        ListNode* t = node->next;
        node->next = node->next->next;
        delete t;
    }

 int main() {
 	ListNode* p1 = new ListNode(1);
 	ListNode* p2 = new ListNode(2);
 	ListNode* p3 = new ListNode(3);
 	ListNode* p4 = new ListNode(4);
 	p1->next = p2;
 	p2->next = p3;
 	p3->next = p4;
 	p4->next = NULL;

	deleteNode(p3);

	ListNode* i;
	for(i = p1; i->next != NULL; ++i) {
		cout << i->val << " ";
	}
	cout << i->val << " " << endl;

 	return 0;
 }



