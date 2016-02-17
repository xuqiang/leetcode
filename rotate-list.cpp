/*

Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
	// 1. 链表收尾项链
	// 2. 两个指针 相差k步 查找第倒数第k个元素
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;

        int len = 1;
        ListNode* p = head;
        while(p->next) {
        	len++;
        	p = p->next;
        }
        k = len - k % len;

        p->next = head; 	// 收尾相连
        for(int step = 0; step < k; ++step) {
        	p = p->next;
        }

        // 断开链接
        head = p->next;
        p->next = nullptr;

        return head;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}