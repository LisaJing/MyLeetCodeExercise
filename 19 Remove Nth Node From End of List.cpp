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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head == NULL || n <= 0)
    		return NULL;
    	ListNode *newHead = new ListNode(0);
    	newHead -> next = head;
    	ListNode *toBeRemovedPre = newHead;
    	ListNode *toBeRemoved = newHead -> next;
        ListNode *endIt = newHead -> next;
        int k = n - 1;
        while(endIt != NULL && k > 0)
        {
        	endIt = endIt -> next;
        	k--;
        }

        while(endIt !=NULL && endIt -> next != NULL)
        {
        	toBeRemovedPre = toBeRemovedPre -> next;
        	toBeRemoved = toBeRemoved -> next;
        	endIt = endIt -> next;
        }
        
        toBeRemovedPre -> next = toBeRemoved -> next;
        delete toBeRemoved;
        toBeRemoved = NULL;
        ListNode *res = newHead -> next;
        delete newHead;
        newHead = NULL;
        return res;

    }
};