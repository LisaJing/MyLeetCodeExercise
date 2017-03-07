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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(root == NULL)
        	return res;
        
        if(root -> left != NULL)
        {
        	std::vector<int> v = inorderTraversal(root -> left);
        	for(std::vector<int>::iterator vit = v.begin();vit != v.end();vit++)
        	{
        		res.push_back(*vit);
        	}
        }
        res.push_back(root -> val);
        if(root -> right != NULL)
        {
        	std::vector<int> v = inorderTraversal(root -> right);
        	for(std::vector<int>::iterator vit = v.begin();vit != v.end();vit++)
        	{
        		res.push_back(*vit);
        	}
        }
        return res;
    }
};
