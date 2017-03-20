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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
            return;
        ListNode *p = head;
        ListNode *q = p;
        while(q -> next != NULL && q -> next-> next != NULL)
        {
            p = p -> next;
            q = q -> next -> next;
        }
        q  = p -> next;
        p -> next = NULL;
        reverseList(q);
        printList(q);
        p = head;
        while(p != NULL && q != NULL)
        {
        	ListNode *r = p -> next;
        	ListNode *s = q -> next;
        	p -> next = q;
        	q -> next = r;
        	p = r;
        	q = s;
        }
    }
    void printList(ListNode * q)
    {
        while(q != NULL)
        {
            cout << q -> val <<"," ;
            q = q -> next;
        }
        cout << endl;
    }
    void reverseList(ListNode * & q)
    {
    	if(q == NULL || q -> next == NULL)
    		return;
    	
    	ListNode * p = NULL;
    	ListNode * r = q -> next;
    	while(r != NULL)
    	{
    		r = q -> next;
    		q -> next = p;
    		p = q;
    		q = r;
    	}
    	q = p;
    }
};
