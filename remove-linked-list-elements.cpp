/*

Remove Linked List Elements


Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5


使用“哑节点”记录链表头部

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode dummy( 0 );
    	dummy.next = head;
    	ListNode* pre = &dummy;
    	ListNode* cur = head;
    	while(cur) {
    		if(cur->val == val) {
    			pre->next = cur->next;
    		} else {
    			pre = cur;
    		}
    		cur = cur->next;
    	}
    	return dummy.next;
    }
};

int main(int argc, char* argv[]) {
  	return 0;
}


















