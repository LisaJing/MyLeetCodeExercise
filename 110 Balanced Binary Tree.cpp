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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        	return true;
        if(root -> left == NULL && root -> right == NULL)
        	return true;
        int leftHeight = 0;
        int rightHeight = 0;
        return isBalancedHelper(root -> left,leftHeight) && isBalancedHelper(root -> right,rightHeight) && (abs(leftHeight - rightHeight) <= 1);

    }
    bool isBalancedHelper(TreeNode * root,int &height)
    {
    	if(root == NULL)
    	{
    		height = 0;
    		return true;
    	}
    	if(root -> left == NULL && root -> right == NULL)
    	{
    		height = 1;
    		return true;
    	}
    	int leftHeight = 0;
        int rightHeight = 0;
        if(isBalancedHelper(root -> left,leftHeight) && isBalancedHelper(root -> right,rightHeight) )
		{
			if(abs(leftHeight - rightHeight) <= 1)
			{
				height = std::max(leftHeight,rightHeight) + 1;
				return true;
			}
			else
				return false;
		}
		return false;

    }
};
