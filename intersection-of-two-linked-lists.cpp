/*
Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.

如果有一个链表为空，返回NULL；先遍历链表得到A、B的长度，如果最后一个节点不同，返回NULL；
使长的链表先走长度差步，然后一起往后走，直到节点相同返回即可。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        	return NULL;
        int lenA = 1;
        ListNode* hA = headA;
        while(hA->next != NULL) {
        	lenA ++;
        	hA = hA->next;
        }

        int lenB = 1;
        ListNode* hB = headB;
        while( hB->next != NULL ) {
        	lenB ++;
        	hB = hB->next;
        }

        if(hA != hB) 
        	return NULL;

        hA = headA;
        hB = headB;
        if( lenA > lenB ) {
        	for(int i = 0; i < lenA - lenB; ++i) {
        		hA = hA->next;
        	}
        } else {
        	for(int i = 0; i < lenB - lenA; ++i) {
        		hB = hB->next;
        	}
        }

        while(hA != hB) {
        	hA = hA->next;
        	hB = hB->next;
        }
        return hA;


    }
};

int main(int argc, char* argv[]) {
	return 0;
}

