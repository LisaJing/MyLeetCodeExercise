class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n <= 0)
            return res;
        vector<int> tmp(n);
        for(int i = 0;i < n;i++)
        {
        	tmp[i] = i;
        }
        vector<vector<int> > permutateVecs;
        getPermutateVecs(tmp,0,n,permutateVecs);
    
        int group_size = permutateVecs.size();
        if(group_size <= 0)
        	return res;
        int column_size = n;
        for(int i = 0;i < group_size;i++)
        {
        	string str(n,'.');
        	std::vector<string> v(n,str);
        	for(int j = 0;j < column_size;j++)
        	{
        	    v[j][permutateVecs[i][j]] = 'Q';
        	  
        	   
        	}
        	res.push_back(v);
        }
        return res;
    }

    void getPermutateVecs(vector<int> tmp,int index,int size,vector<vector<int> > &permutateVecs)
    {
        
    	if(index == size)
    	{
    	 
    		for (int i = 0; i < tmp.size(); ++i)
    		{
    			for (int j = i + 1; j < tmp.size(); ++j)
    			{
    				if(tmp[i] - tmp[j] == i - j || tmp[i] - tmp[j] == j - i)
    				{
    					return;
    				}
    			}
    		}
    
    		permutateVecs.push_back(tmp);
    		return;
    	}

    	for(int i = index;i < size;i++)
    	{
    		swap(tmp[i],tmp[index]);
    		getPermutateVecs(tmp,index + 1,size,permutateVecs);
    		swap(tmp[i],tmp[index]);
    	}
    }
};
