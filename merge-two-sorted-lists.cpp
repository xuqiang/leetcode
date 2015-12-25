/*

Merge Two Sorted Lists

*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
 		ListNode node(0);
 		ListNode* p = &node;
 		while(l1 && l2) {
 			if(l1->val < l2->val) {
 				p->next = l1;
 				l1 = l1->next;
 			} else {
 				p->next = l2;
 				l2 = l2->next;
 			}
 			p = p->next;
 		}       
 		if(l1) { 
 			p->next = l1;
 		} else if(l2) {
 			p->next = l2;
 		}
 		return node.next;
    }
};


int main(int argc, char* argv[]) {
	return 0;
}