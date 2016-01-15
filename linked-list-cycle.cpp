/*

Linked List Cycle

查看链表中是否存在环

*/


#include <vector>
#include <string>
#include <iostream>
#include <queue>
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
    bool hasCycle(ListNode *head) {
  		if(head == NULL || head->next == NULL) return false;
  		ListNode* fast = head;
  		ListNode* slow = head;
  		while( fast != NULL && fast->next != NULL ) {
  			slow = slow->next;
  			fast = fast->next->next;
  			if( fast == slow ) return true;
  		}
  		return false;

    }
};

int main(int argc, char* argv[]) {
	return 0;
}