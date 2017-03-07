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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(root == NULL)
        	return res;
        TreeNode *p = root;
        stack<TreeNode *> treeNodeStack;
        while(p != NULL || !treeNodeStack.empty())
        {
        	while(p != NULL)
        	{
        		treeNodeStack.push(p);
        		p = p -> left;
        	}
        	while(p == NULL && !treeNodeStack.empty())
        	{
        		p = treeNodeStack.top();
        		res.push_back(p -> val);
        		treeNodeStack.pop();
        		p = p -> right;
        		
        	}
        }
        return res;
    }
};
