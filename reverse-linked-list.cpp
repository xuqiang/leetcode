/*

Reverse a singly linked list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <string>
#include "common.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (!head) return NULL;
    	ListNode* prev = NULL;
	  	ListNode* curr = head;
	  	while (curr) {
	    	ListNode* next = curr->next;
	    	curr->next = prev;
	    	prev = curr;
	    	curr = next;
	  	}
	  	return prev;
    }
};


int main(int argc, char* argv[]) {
	return 0;
}