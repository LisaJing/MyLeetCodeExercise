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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        	return NULL;
        TreeNode *p = root;
        queue<TreeNode *> queueNode;
        queueNode.push(p);
        while(!queueNode.empty())
        {
        	TreeNode * p = queueNode.front();
        	TreeNode *tmp = p -> left;
        	p -> left = p -> right;
        	p -> right = tmp;
        	queueNode.pop();

        	if(p -> left != NULL)
        		queueNode.push(p -> left);
        	if(p -> right != NULL)
        		queueNode.push(p -> right);
        	
        }
        return root;
    }
};
