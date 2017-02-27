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
        ListNode *Head = new ListNode(0);
        Head -> next = head;
        ListNode *pNode = Head -> next;
        ListNode *qNode = Head;
        while(pNode != NULL)
        {
            if(pNode -> val == val )
            {
                qNode -> next = pNode -> next;
                delete pNode;
                pNode = qNode -> next;
            }
            else
            {
                pNode = pNode -> next;
                qNode = qNode -> next;
            }
        }
        ListNode *res = Head -> next;
        delete Head;
        Head = NULL;
        return res;
    }
};