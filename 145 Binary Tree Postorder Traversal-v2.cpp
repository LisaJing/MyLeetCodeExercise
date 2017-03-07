class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(root == NULL)
        	return res;
        stack<TreeNode *> treeNodeStack;
		TreeNode *p = root;
		TreeNode *pPopNode = NULL;
        while(p != NULL || !treeNodeStack.empty())
        {
        	while(p != NULL)
        	{
        	
        		treeNodeStack.push(p);
        		p = p -> left;
        	}
        	while(p == NULL && !treeNodeStack.empty())
        	{
        		p = treeNodeStack.top();
        		if(p -> right != NULL)
        		{
        			p = p -> right;
        		}
        		else
        		{
        			pPopNode = p;
        			res.push_back(pPopNode -> val);
        			treeNodeStack.pop();

        			if(treeNodeStack.empty())
        				return res;

        			
        			p = treeNodeStack.top();
        			while(p -> right == pPopNode)
        			{
        				pPopNode = p;
        				res.push_back(pPopNode -> val);
        				treeNodeStack.pop();
        				if(treeNodeStack.empty())
        					return res;
        				p = treeNodeStack.top();
        			}
        			if(p -> left == pPopNode)
        			{
        				p = p -> right;
        			}
        		}
        		
        	}
        }
        return res;
    }
};
