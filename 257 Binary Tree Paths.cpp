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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> res;
        std::vector<int> v;
        if(root == NULL)
        	return res;
            
        binaryTreePathsHelper(root,v,res);        
        return res; 
    }

    void binaryTreePathsHelper(TreeNode* root,std::vector<int> &v,vector<string> &res)
	{
		v.push_back(root -> val);
		if(root -> left == NULL && root -> right == NULL)
		{
			string str = printStr(v);
			res.push_back(str);
		}
		if(root -> left != NULL)
		{
			binaryTreePathsHelper(root -> left,v,res);
		}
		if(root -> right != NULL)
		{
			binaryTreePathsHelper(root -> right,v,res);
		}
		v.pop_back();
	}

   string printStr(std::vector<int> &v)
   {
   		string res;
   		if(v.empty())
   			return res;
   	    std::vector<int>::iterator vit = v.begin();
   	    while(vit != v.end() - 1)
   	    {
			stringstream ss;
			ss.clear();
			string stmp;
			stmp.clear();
			ss << (*vit);
			ss >> stmp;
			res += stmp;
			res += "->";
   	    	vit++;
   	    }
   	    stringstream ss;
		ss.clear();
		string stmp;
		stmp.clear();
		ss << (*vit);
		ss >> stmp;
		res += stmp;
   	   	return res;
   }	

};
