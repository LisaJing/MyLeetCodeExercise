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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *p = l3;
        int add_one = 0;
        int curNo = 0;
        while(l1 != NULL || l2 != NULL || add_one != 0 )
        {
            curNo = (add_one + (l1 == NULL ? 0:l1 -> val) + (l2 == NULL? 0: l2 -> val) ) % 10;
            add_one = (add_one + (l1 == NULL ? 0:l1 -> val) + (l2 == NULL? 0: l2 -> val) ) / 10;
            ListNode *newNode = new ListNode(curNo);
            p -> next = newNode;
            p = newNode;
            l1 =  (l1 == NULL ? NULL:l1 -> next);
            l2 =  (l2 == NULL ? NULL:l2 -> next);
        }
        ListNode *tmp = l3;
        l3 = tmp -> next;
        delete tmp;
        return l3;
    }
};