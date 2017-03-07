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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int> > res;
        if(root == NULL)
        	return res;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
		TreeNode * p = root;
        s1.push(p);
        bool leftToRight = true;
        while(!s1.empty() || !s2.empty())
        {
        	std::vector<int> v;
        	if(leftToRight)
        	{
        		leftToRight = false;
        		while(!s1.empty())
        		{
        			TreeNode * tmp = s1.top();
       				s1.pop();
       				v.push_back(tmp -> val);
       				if(tmp -> left != NULL)
       				{
       					s2.push(tmp -> left);
       				}
       				if(tmp -> right != NULL)
       				{
       					s2.push(tmp -> right);
       				}
       			}
       		}
       		else
       		{
       			leftToRight = true;
       			while(!s1.empty())
       			{
       				TreeNode * tmp = s1.top();
       				s1.pop();
       				v.push_back(tmp -> val);
       				if(tmp -> right != NULL)
       				{
       					s2.push(tmp -> right);
       				}
       				if(tmp -> left != NULL)
       				{
       					s2.push(tmp -> left);
       				}
       				
       			}
       		}
       		res.push_back(v);
       		std::swap(s1,s2);
        }
        return res;

    }
};
