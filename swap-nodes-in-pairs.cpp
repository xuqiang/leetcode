/*

Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

增加哑节点

*/


#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
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
    ListNode* swapPairs(ListNode* h) {
        ListNode dummy(0);
       	dummy.next = h;
       	ListNode* pre = &dummy;
       	while(h && h->next) {
       		ListNode* t = h->next->next;
       		pre->next = h->next;  
       		h->next->next = h;
       		h->next = t;  
       		pre = h;  
       		h = t;
       	}
       	return dummy.next;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}

