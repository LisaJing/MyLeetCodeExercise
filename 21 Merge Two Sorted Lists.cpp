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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p = newHead;
        bool p1Flag = true;
        while(p1 != NULL || p2 != NULL)
        {
        	p -> next = (p1 != NULL ? p1 -> val:INT_MAX) < (p2 != NULL ? p2->val : INT_MAX) ? (p1Flag = true,p1):(p1Flag = false,p2);
        	if(p1Flag)
        		p1 = p1->next;
        	else
        		p2 = p2->next;
        	p = p -> next;
        }
        ListNode *res = newHead -> next;
        delete newHead;
        newHead = NULL;
        return res;
    }
};