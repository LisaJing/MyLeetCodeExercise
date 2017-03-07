/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
        	return res;
        stack<TreeNode *> treeNodeStack;
        TreeNode *p = root;
        while(p != NULL || !treeNodeStack.empty())
        {
        	while(p != NULL)
        	{
        		res.push_back(p -> val);
        		treeNodeStack.push(p);
        		p = p -> left;	
        	}
        	while(p == NULL && !treeNodeStack.empty())
        	{
        		p = treeNodeStack.top() -> right;
        		treeNodeStack.pop();
        	}
        	
        } 
        return res;
    }
};
