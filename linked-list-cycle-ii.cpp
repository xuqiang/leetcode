/*

Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

http://www.cnblogs.com/x1957/p/3406448.html


*/

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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL) return NULL;
        ListNode* S = head;
        ListNode* F = head;
        
        while(F != NULL){
            if(F) F = F -> next;
            if(F) F = F -> next;
            if(S) S = S -> next;
            if(F != NULL && F == S){
                S = head;
                while(S != F){
                    S = S -> next;
                    F = F -> next;
                }
                return S;
            }
        }
        return NULL;
    }
};