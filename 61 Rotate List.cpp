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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k < 0)
        	return NULL;
       	if(k == 0)
       		return head;	

        ListNode * pre = head;
        int length = 1;
        bool kLargerThanLength = false;
        for(int i = 0;i < k - 1;i++)
        {
        	if(pre -> next == NULL)
        	{
        		kLargerThanLength = true;
        		break;
        	}
        	length++;
        	pre = pre -> next;
        }

        if(kLargerThanLength)
        {
			int new_k = k % length;
			if(new_k == 0)
				return head;
			pre = head;
			for(int i = 0;i < new_k - 1;i++)
        	{
        		pre = pre -> next;
        	}
        }


        ListNode * newHead = new ListNode(0);
        newHead -> next = head;
        ListNode * q = newHead;
        ListNode * cur = head;
        while(pre -> next != NULL)
        {
        	pre = pre -> next;
        	q = q -> next;
        	cur = cur -> next;
        }
        q -> next = NULL;
        pre -> next = newHead -> next;
        delete newHead;
        newHead = NULL;
        return cur;
    }
};
