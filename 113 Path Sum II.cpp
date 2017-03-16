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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int> > res;
        if(root == NULL)
        	return res;
        std::vector<int> nums;
        int curSum = 0;
        getPathSumHelper(root,curSum,nums,sum,res);
        return res;

    }
    void getPathSumHelper(TreeNode *root,int &curSum,vector<int> &nums,int sum,std::vector<std::vector<int> >& res)
	{
		if(root == NULL)
			return;
        
		curSum += root -> val;
		cout << "root:" <<root -> val<<", curSum:" << curSum << endl;
		nums.push_back(root -> val);
		if(root -> left == NULL && root -> right == NULL)
		{
			if(curSum == sum)
			{
				res.push_back(nums);
			}
			nums.pop_back();
			curSum -= root -> val;
			return;
		}
		if(root -> left != NULL)
		{
			getPathSumHelper(root -> left,curSum,nums,sum,res);
		}
		if(root -> right != NULL)
		{
			getPathSumHelper(root -> right,curSum,nums,sum,res);
		}

		nums.pop_back();
		curSum -= root -> val;
	}
};
