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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *OddHead = new ListNode(0);
        ListNode *EvenHead = new ListNode(0);
        ListNode *pOdd = OddHead;
        ListNode *pEven = EvenHead;
        ListNode *p = head;
        bool oddflag = true;
        while(p != NULL)
        {
        	if(oddflag)
        	{
        		pOdd -> next = p;
        		pOdd = pOdd -> next;
        		oddflag = false;
        	}
        	else
        	{
        		pEven -> next = p;
        		pEven = pEven -> next;
        		oddflag = true;
        	}
        	p = p -> next;
        }
        pOdd -> next = EvenHead -> next;
        pEven -> next = NULL;
        delete EvenHead;
        EvenHead = NULL;
        head = OddHead -> next;
        delete OddHead;
        OddHead = NULL;
        return head;

    }
};