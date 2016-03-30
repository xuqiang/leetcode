/*

Merge k Sorted Lists



Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.




*/


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)return NULL;
        while(n >1) {
            int k = (n+1)/2;
            for(int i = 0; i < n/2; i++)
                lists[i] = merge2list(lists[i], lists[i + k]);
            n = k;
        }
        return lists[0];
    }

    ListNode *merge2list(ListNode *head1, ListNode*head2) {
        ListNode node(0), *res = &node;
        while(head1 && head2) {
            if(head1->val <= head2->val) {
                res->next = head1;
                head1 = head1->next;
            } else {
                res->next = head2;
                head2 = head2->next;
            }
            res = res->next;
        }
        if(head1)
            res->next = head1;
        else if(head2)
            res->next = head2;
        return node.next;
    }
};