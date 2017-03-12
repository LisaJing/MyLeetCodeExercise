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
    void flatten(TreeNode* root) {
        if(root == NULL || root ->left == NULL && root -> right == NULL)
        {
        	return ;
        }
        vector<TreeNode *> queueNode;
        preOrderTraverse(root,queueNode);
        std::vector<TreeNode *>::iterator vTreeNodeIt = queueNode.begin();
        while(vTreeNodeIt != queueNode.end() - 1)
        {
        	TreeNode * p = *vTreeNodeIt;
        	p -> left = NULL;
        	p -> right = *(vTreeNodeIt + 1);
        	vTreeNodeIt++;
        }
        (*vTreeNodeIt) -> left = NULL;
        (*vTreeNodeIt) -> right = NULL;
        
    }

    void preOrderTraverse(TreeNode *root,vector<TreeNode*> & queueNode)
    {
    	if(root == NULL)
    		return ;
    	queueNode.push_back(root);
    	if(root -> left != NULL)
    		preOrderTraverse(root -> left,queueNode);
    	if(root -> right != NULL)
    		preOrderTraverse(root -> right,queueNode);
    }

};
