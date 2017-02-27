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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	int k = n - m;
    	if(head == NULL || m <= 0 || n <= 0 || k <= 0)
    		return head;
    	ListNode *newNode = new ListNode(0);
    	newNode -> next = head;
    	ListNode *preNode = newNode;
        ListNode *pNode = head;
        

        while(pNode != NULL && m > 1)
        {
        	pNode = pNode -> next;
        	preNode = preNode -> next;
        	m--;
        }
        if(pNode == NULL)
        	return head;
        ListNode *postNode = pNode -> next;
        for(int i = 0;i < k;i++)
        {
        	if(postNode != NULL)
        	{
        		ListNode *tmp = postNode -> next;
        		postNode -> next = pNode;
        		pNode = postNode;
        		postNode = tmp;
        	}
        }
        ListNode *tmp = preNode -> next;
        preNode -> next = pNode;
        tmp -> next = postNode;
        head = newNode -> next;
        delete newNode;
        newNode = NULL;
        return head;
    }
};