/*
 
 Add Two Numbers

 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

链表 数字 求和

两个链表 归并 

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        int carry = 0;
        ListNode* prev = &dummy;
        for( ListNode* pa = l1, *pb = l2; 
        	pa != nullptr || pb != nullptr;
        	pa = (pa == nullptr ? nullptr : pa->next),
        	pb = (pb == nullptr ? nullptr : pb->next),
        	prev = prev->next ) {
        	const int ai = (pa == nullptr ? 0 : pa->val);
        	const int bi = ( pb == nullptr ? 0 : pb->val );
        	const int val = ( ai + bi + carry ) % 10;
        	carry = ( ai + bi + carry ) / 10;
        	prev->next = new ListNode(val);
        }
        if(carry > 0) {
        	prev->next = new ListNode(carry);
        }
        return dummy.next;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}