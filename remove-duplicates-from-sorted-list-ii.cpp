/*

Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

链表 递归

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
   ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * p = head;
        while(p->next != NULL && p->val == p->next->val){
            p = p->next;
        }
    
        if(p != head){
            while(head != p->next)
            {
                ListNode * tmp = head;
                head = head->next;
                free(tmp);
            }
    
            return deleteDuplicates(p->next);
        }
    
        head->next = deleteDuplicates(head->next);
        return head;
    }
};