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
    int maxDepth(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	int res = 0;
    	TreeNode *p = root;
    	queue<TreeNode *> q1;
    	queue<TreeNode *> q2;
    	q1.push(root);
    	while(!q1.empty())
    	{
    		res++;
    		while(!q1.empty())
    		{
    			TreeNode * tmp = q1.front();
    			q1.pop();
    			if(tmp -> left != NULL)
    			{
    				q2.push(tmp -> left);
    			}
    			if(tmp -> right != NULL)
    			{
    				q2.push(tmp -> right);
    			}
    		}
    		std::swap(q1,q2);
    	}
        return res;
    }
};
