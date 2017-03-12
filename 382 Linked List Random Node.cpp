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
        length = 0;
        ListNode *p = head;
        while(p != NULL)
        {
            p = p -> next;
            length++;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int randNo = rand() % length;
        ListNode *p = listHead;
        while(randNo != 0)
        {
            p = p -> next;
            randNo--;
        }
        return p -> val;
    }


private:
    ListNode * listHead;
    int length;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
