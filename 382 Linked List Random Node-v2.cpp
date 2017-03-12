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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        listHead = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = listHead;
        if(p == NULL)
            return -1; //Exception
            
        int res = p -> val;
        p = p -> next;
        int i = 2;
        while(p != NULL)
        {
            int prob = rand() % i;
            if(prob == 0)
                res = p -> val;
            p = p -> next;
            i++;
        }
        return res;
        
    }
private:
    ListNode *listHead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
