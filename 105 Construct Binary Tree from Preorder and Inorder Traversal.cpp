/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef vector<int>::iterator Iterator;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_size = preorder.size();
        int in_size = inorder.size();
        if(pre_size <= 0 || in_size <= 0)
        	return NULL;
        TreeNode *newNode = new TreeNode(preorder[0]);
        std::vector<int>::iterator in_it = inorder.begin();
        for(;in_it != inorder.end();in_it++)
        {
            if(*in_it == preorder[0])
                break;
        }
        int left_size = in_it - inorder.begin();
        newNode -> left = buildTreeHelper(preorder,inorder,preorder.begin() + 1,preorder.begin() + 1 + left_size,inorder.begin(),in_it);
        newNode -> right = buildTreeHelper(preorder,inorder,preorder.begin() + 1 + left_size,preorder.end(),in_it + 1,inorder.end());
        return newNode;
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,Iterator preLeftIt,Iterator preRightIt,Iterator inLeftIt,Iterator inRightIt)
    {
        if(preLeftIt == preRightIt || inLeftIt == inRightIt)
            return NULL;
        TreeNode *newNode = new TreeNode(*preLeftIt);
        Iterator in_it = inLeftIt;
        for(;in_it != inRightIt;in_it++)
        {
            if(*in_it == *preLeftIt)
                break;
        }
        int left_size = in_it - inLeftIt;
        
        newNode -> left = buildTreeHelper(preorder,inorder,preLeftIt+1,preLeftIt+1+left_size,inLeftIt,in_it);
        newNode -> right = buildTreeHelper(preorder,inorder,preLeftIt+1+left_size,preRightIt,in_it+1,inRightIt);
        return newNode;
    }
};