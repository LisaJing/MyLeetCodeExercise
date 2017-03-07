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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(root == NULL)
        	return res;
        res.push_back(root -> val);
        if(root -> left != NULL)
        {
        	std::vector<int> v = preorderTraversal(root -> left);
        	for(std::vector<int>::iterator vit = v.begin();vit != v.end();vit++)
        	{
        		res.push_back(*vit);
        	}
        }
        if(root -> right != NULL)
        {
        	std::vector<int> v = preorderTraversal(root -> right);
        	for(std::vector<int>::iterator vit = v.begin();vit != v.end();vit++)
        	{
        		res.push_back(*vit);
        	}
        }
        return res;
        
    }
};
