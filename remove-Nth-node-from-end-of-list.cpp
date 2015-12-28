/*

Remove Nth Node From End of List


Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/

#include <stack>
#include <iostream>
#include <string>
#include "common.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) 
        	return NULL;
        ListNode* fast = head;
    	ListNode* slow = head;

    	for(int i = 0; i < n; ++i) {
    		fast = fast->next;
    	}

    	if(fast != NULL) {
        	while(fast->next != NULL)
        	{
        	    fast = fast->next;
        	    slow = slow->next;
        	}

        	ListNode *tmp = slow->next;
        	slow->next = tmp->next;
        	delete tmp;

        	return head;
    	}
    	else {
    		ListNode *tmp = head;
    		head = head->next;
    		delete tmp;

    		return head;
    	} 
    }   
};

int main(int argc, char* argv[]) {
	return 0;
}