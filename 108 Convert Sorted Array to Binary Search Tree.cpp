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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size <= 0)
            return NULL;
        
        TreeNode *root = new TreeNode(nums[size >> 1]);
        int leftstart = 0;
        int leftend = (size >> 1) - 1;
        int rightstart = (size >> 1) + 1;
        int rightend = size - 1;
        root -> left = sortedArrayToBSTHelper(nums,leftstart,leftend);
        root -> right = sortedArrayToBSTHelper(nums,rightstart,rightend);
        return root;
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int start,int end)
    {
        if(start > end)
            return NULL;
        TreeNode *root = new TreeNode(nums[(start + end) >> 1]);
        int leftstart = start;
        int leftend = ((start + end) >> 1) - 1;
        int rightstart = ((start + end) >> 1) + 1;
        int rightend = end;
        root -> left = sortedArrayToBSTHelper(nums,leftstart,leftend);
        root -> right = sortedArrayToBSTHelper(nums,rightstart,rightend);
        return root;
    }
};
