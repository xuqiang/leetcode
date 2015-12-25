/*
 
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != NULL) {
        	if(cur->val == pre->val) {
        		pre->next = cur->next;
        	} else {
        		pre = cur;
        	}
        	cur = cur->next;
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}