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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return true;
        if(head -> next -> next == NULL )
        {
            if(head -> val == head -> next -> val)
                return true;
            else
                return false;
        }
            
        ListNode *p = head;
        ListNode *q = head;
        while(q -> next != NULL && q -> next -> next != NULL)
        {
            p = p -> next;
            q = q -> next -> next;
        }
        if(q -> next == NULL) //odd number nodes
        {
            ListNode *reverseHead = p -> next;   
            reverseHead = reverseList( reverseHead );
            p -> next = NULL;
            cout << "reverseHead:" <<reverseHead -> val << endl;
            return isEqual(head,p,reverseHead,NULL);
        }
        else //even number nodes
        {
            if(p -> val != p -> next -> val)
                return false;
            ListNode *reverseHead = p -> next -> next;
            reverseHead = reverseList( reverseHead );
            p -> next -> next = NULL;
            p -> next = NULL;
            return isEqual(head,p,reverseHead,NULL);
        }
    }
    
    ListNode *reverseList(ListNode *head)
    {
        if((head == NULL) || (head -> next == NULL))
            return head;
        ListNode *pre = NULL;
        ListNode *p = head;
        ListNode *post = p -> next;
        while(post != NULL)
        {
            p -> next = pre;
            pre = p;
            p = post;
            post = post -> next;
        }
        p -> next = pre;
        return p;
    }
    
    bool isEqual(ListNode *leftstart,ListNode *leftend,ListNode *rightstart,ListNode *rightend)
    {
        while(leftstart  != leftend && rightstart  != rightend)
        {
            if(leftstart -> val != rightstart -> val)
                return false;
            leftstart = leftstart -> next;
            rightstart = rightstart -> next;
        }
        return true;
    }
};
