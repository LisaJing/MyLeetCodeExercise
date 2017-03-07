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
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        vector<std::vector<int> > res;
        if(root == NULL)
        	return res;
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
        	std::vector<int> sameLevelNode;
        	while(!q1.empty())
        	{
        		TreeNode *curNode = q1.front();
        		q1.pop();
        		sameLevelNode.push_back(curNode -> val);
        		if(curNode -> left != NULL)
        			q2.push(curNode -> left);
        		if(curNode -> right != NULL)
        			q2.push(curNode -> right);
        	}
        	res.push_back(sameLevelNode);
        	std::swap(q1,q2);
        }
        return res;
    }
};
