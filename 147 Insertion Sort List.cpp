 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	if(head == NULL || head -> next == NULL)
    		return head;
    	ListNode * newHead = new ListNode(0);
    	newHead -> next = head;
    	ListNode *tmpNode = head -> next;
    	ListNode *tmpNodeNext;
    	head -> next = NULL;
    	while(tmpNode != NULL)
    	{
    	//	cout << "正在处理: " << tmpNode -> val << endl; 
    		tmpNodeNext = tmpNode -> next;
    		insertNodeLocation(newHead,tmpNode);
    		tmpNode = tmpNodeNext;

    	}
    	ListNode *resNode = newHead -> next;
        delete newHead;
        newHead = NULL;
        return resNode;
    }
    
    
    void insertNodeLocation(ListNode *beginNode,ListNode *tmpNode)
    {
    	ListNode *curNode = beginNode -> next;
    	ListNode *preCurNode = beginNode;
    	while(curNode != NULL && tmpNode -> val > curNode -> val)
    	{
    		//cout << "curNode : " << curNode -> val << endl;
    		preCurNode = preCurNode -> next;
    		curNode = curNode -> next;
    	}
    	if(curNode == NULL)
    	{
    		tmpNode -> next = NULL;
    		preCurNode -> next = tmpNode;
    	}
    	else
    	{
    		tmpNode -> next = preCurNode -> next;
    		preCurNode -> next = tmpNode;
    	
    	}
    }
};
