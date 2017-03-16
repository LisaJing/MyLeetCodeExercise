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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
        	return false;
        int curSum = 0; 
        return hasPathSumHelper(root,curSum,sum);
    }
    bool hasPathSumHelper(TreeNode * root,int & curSum,int sum)
    {
    	if(root == NULL)
    		return false;
    	curSum += root -> val;
    	cout <<"root: " << root -> val << endl;
    	cout <<"curSum:" <<curSum << endl;
    	if(root -> left == NULL && root -> right == NULL)
    		if(curSum == sum)
    			return true;
    		else
    		{
    		    curSum -= root -> val;
    			return false;
    		}

    	if((root -> left != NULL) && hasPathSumHelper(root -> left,curSum,sum))
    		return true;
    	else if((root -> right != NULL) && hasPathSumHelper(root -> right,curSum,sum))
    		return true;
    	

    	curSum -= root -> val;
    	return false;

    }
};
