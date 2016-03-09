/*
 Odd Even Linked List


Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking 
about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

一个指针p指向当前遍历的奇数节点的最后一个位置，另一个指针q指向待提取的奇数节点的前一个位置。

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* p = head; 
        ListNode* q = head;
        while(q) {
        	q = q->next;
        	if (!q || !q->next) break;
        	ListNode *next_p = p->next, *next_q = q->next;
        	q->next = next_q->next;
        	p->next = next_q;
			next_q->next = next_p;
			p = p->next;
        }
        return head;
    }
};

int main(int argc, char* argv[] ) {
	
}
