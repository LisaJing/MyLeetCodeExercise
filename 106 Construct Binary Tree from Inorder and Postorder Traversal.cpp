//106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int inSize = inorder.size();
    	int postSize = postorder.size();
    	if (inSize != postSize || inSize <= 0)
    	{
    		return NULL;
    	}
    	TreeNode *root = new TreeNode(postorder[postSize - 1]);
    	
    	int leftInSize = 0;
    	for(;leftInSize < inSize;leftInSize++)
    	{
    		if(inorder[leftInSize] == root -> val)
    			break;
    	}
    	if(leftInSize == inSize)
    	{
    		return NULL;  //error
    	}
    	int leftInStart = 0;
    	int leftPostLen = leftInSize;
    	int leftPostStart = 0;
    
    	root -> left = buildTreeCore(inorder,leftInStart,leftInSize,postorder,leftPostStart,leftPostLen);
    	int rightInstart = leftInStart + leftInSize + 1;
    	int rightInLen = inSize - 1 - leftInSize;
    	int rightPostStart = leftPostStart + leftPostLen;
    	int rightPostLen = rightInLen;
        
    	root -> right = buildTreeCore(inorder,rightInstart,rightInLen,postorder,rightPostStart,rightPostLen);
    	return root;
    }


    TreeNode *buildTreeCore(std::vector<int> &inorder,int inStart,int inLen,std::vector<int> &postorder,int postStart,int postLen)
    {
    		if(inLen != postLen || inLen <= 0)
    			return NULL;

    		TreeNode *root = new TreeNode(postorder[postStart + postLen - 1]);
    		int leftIndex = inStart;
    		for(;leftIndex < inStart + inLen;leftIndex++)
   	    	{
   	    	    
    			if(inorder[leftIndex] == root -> val)
    				break;
    		}

		    if(leftIndex  == inStart + inLen)
   	 	    {
    			return root;  //error
    		}
    		int leftInStart = inStart;
    		int leftInSize = leftIndex - leftInStart;
    		int leftPostLen = leftInSize;
    		int leftPostStart = postStart;
    		
    		root -> left = buildTreeCore(inorder,leftInStart,leftInSize,postorder,leftPostStart,leftPostLen);
    		int rightInstart = leftInStart + leftInSize + 1;
    		int rightInLen =  inLen - leftInSize - 1;
    		int rightPostStart = leftPostStart + leftPostLen;
    		int rightPostLen = rightInLen;
    		
    		root -> right = buildTreeCore(inorder,rightInstart,rightInLen,postorder,rightPostStart,rightPostLen);
    		return root;
    }
};
