/*
 * 判断链表是否是回文链表( 对称 )
 *
 * 两个指针，一个每次走一步 另外一个每次走两部，并且通过压栈的形式
 */ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x) , next(NULL) { }
};

bool isPalindrome(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	vector<int> stack;
	while( fast->next != NULL && fast->next->next != NULL ) {
		stack.push_back( slow->val );
		fast = fast->next->next;
		slow = slow->next;
	}
	// 偶数个节点
	if( fast->next != NULL ) {
		stack.push_back( slow->val );
	} 
	slow = slow->next;
	while(slow != NULL) {
		int pop_val = stack.back();;
		stack.pop_back();
		if(pop_val != slow->val) 
			return false;
		slow = slow->next;
	}
	return true;
}

int main() {
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(3);
	
	a->next = b;	b->next = c;	c->next = d;	d->next = e;
	
	cout << isPalindrome(a) << endl;


	return 0;
}
