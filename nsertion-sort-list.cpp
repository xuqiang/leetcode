/*

Insertion Sort List


Sort a linked list using insertion sort.


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
    ListNode* insertionSortList(ListNode* head) {
    	// 新链表的头
        ListNode* dummy = new ListNode(0);
        while (head != NULL) {
        	ListNode *temp = dummy;
        	ListNode *next = head->next;
        	 while (temp->next != NULL && temp->next->val < head->val) {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy->next;
    }
};