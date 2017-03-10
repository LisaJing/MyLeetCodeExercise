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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)
        	return NULL;
        ListNode *p = head;
        ListNode *q = head;
        while(q -> next != NULL && q -> next -> next != NULL)
        {
        	p = p -> next;
        	q = q -> next -> next;
        	if(p == q)
        		break;
        }
        if(q -> next == NULL || q -> next -> next == NULL)
        	return NULL;
        int circleLen = 1;
        while(p -> next != q)
        {
        	circleLen++;
        	p = p -> next;
        }
       	//cout << circleLen << endl; 
        p = head;
        q = head;
        for(int i = 0;i < circleLen;i++)
        {
        	p = p -> next;
        }
        while(p != q)
        {
        	p = p -> next;
        	q = q -> next;
        }
       // cout <<"入口" <<p->val << endl;
        return p;
    }
};
