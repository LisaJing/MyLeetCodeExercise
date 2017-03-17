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
    int sumOfLeftLeaves(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	int sum = 0;
    	sum = getSum(root);
    	return sum;

    }
    int getSum(TreeNode * root)
    {
    	if(root == NULL)
    		return 0;
    	int sum = 0;
    	
    	if((root -> left != NULL ) && (root -> left -> left == NULL && root -> left -> right == NULL))
    	{
    		sum += root -> left -> val;
    	}
    	else
    		sum += getSum(root -> left);
    	return sum += getSum(root -> right);
    }
};
