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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
        	return NULL;
        ListNode *newHead = new ListNode(0);
        newHead -> next = head;
        ListNode * pre = newHead;
        ListNode * p = head;
        ListNode * q = head -> next;
        bool trueP = true;
        while(q != NULL)
        {
        	while(q != NULL && q -> val == p -> val)
        	{
        		trueP = false;
        		p -> next = q -> next;
        		delete q;
        		q = p -> next;
        	}
        	if(q == NULL)
        	{
        		if(!trueP)
        		{
        			pre -> next = NULL;
        			delete p;
        		}

        	}
        	else if(!trueP)
        	{
        		pre -> next = p -> next;
        		delete p;
        		p = pre -> next;
        		q = p -> next;
        		trueP = true;
        	}
        	else
        	{
        		pre = pre -> next;
        		p = p -> next;
        		q = p -> next;
        		trueP = true;
        	}
        }
        ListNode *tmp = newHead -> next;
        delete newHead;
        newHead = NULL;
        return tmp;
    }
};
