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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        	return head;
        
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *post = cur -> next;
        while(post != NULL)
        {
        	cur -> next = pre;
        	pre = cur;
        	cur = post;
        	post = post -> next;
        }
        cur -> next = pre;
        head = cur;
        return head;
    }
};