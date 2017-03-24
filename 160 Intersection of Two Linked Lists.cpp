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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int sizeA = 0;
        int sizeB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA != NULL)
        {
            sizeA++;
            pA = pA -> next;
        }
        while(pB != NULL)
        {
            sizeB++;
            pB = pB -> next;
        }
        pA = headA;
        pB = headB;
        if(sizeA > sizeB)
        {
            int earlyStep = sizeA - sizeB;
            for(int i = 0;i < earlyStep;i++)
            {
                pA = pA -> next;
            }
            while(pA != NULL && pB != NULL && pA != pB)
            {
                pA = pA -> next;
                pB = pB -> next;
            }
            if(pA == NULL || pB == NULL)
                return NULL;
            else
                return pA;
        }
        else
        {
            int earlyStep = sizeB - sizeA;
            for(int i = 0;i < earlyStep;i++)
            {
                pB = pB -> next;
            }
            while(pA != NULL && pB != NULL && pA != pB)
            {
                pA = pA -> next;
                pB = pB -> next;
            }
            if(pA == NULL || pB == NULL)
                return NULL;
            else
                return pA;
        }
    }
};
