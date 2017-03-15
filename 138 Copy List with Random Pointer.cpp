/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head == NULL)
    		return NULL;
        RandomListNode *p = head;
        while(p != NULL)
        {
            
        	RandomListNode * newNode = new RandomListNode(p -> label);
        	newNode -> next = p -> next;
        	p -> next = newNode;
        	p = newNode -> next;
        	
        }
        p = head;
        RandomListNode *newHead = head -> next;
        RandomListNode *q = head -> next;
        while(q  != NULL && q -> next  != NULL)
        {
        	if(p -> random != NULL)
        		q -> random = p -> random -> next;
        	else
        		q -> random = NULL;
        	p = q -> next;
        	q = q -> next -> next;
        }
        if(p -> random != NULL)
        	q -> random = p -> random -> next;
        else
        	q -> random = NULL;
        	

        	
        p = head;
        q = head -> next;
        while(q != NULL && q -> next != NULL)
        {
            p -> next = q -> next;
            q -> next = q -> next -> next;
            p = p -> next;
            q = q -> next;
        }
        if(p != NULL)
            p -> next = NULL;
        return newHead;
    }
};
