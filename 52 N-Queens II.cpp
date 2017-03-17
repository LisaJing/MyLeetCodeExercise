class Solution {
public:
    int totalNQueens(int n) {
        std::vector<int>  permutate(n);
        std::vector<std::vector<int> > res;
        int tmp = 0;
        for(std::vector<int>::iterator vit = permutate.begin();vit != permutate.end();vit++)
        {
            *vit = (tmp++);
        }
        getPermutates(permutate,0,res);
    	return res.size();
    }

    void getPermutates(std::vector<int> permutate,int index,std::vector<std::vector<int> >& res)
    {
    	int size = permutate.size();
    	if(index == size)
    	{
    		for(int i = 0; i < size;i++)
    		{
    			for(int j = i + 1;j < size;j++)
    			{
    				if(permutate[i] - permutate[j] == i - j || permutate[i] - permutate[j] == j - i)
    					return;
    			}
    		}
    		res.push_back(permutate);
    		
    	}

    	for(int i = index;i < size;i++)
    	{
    		swap(permutate[index],permutate[i]);
    		getPermutates(permutate,index + 1,res);
    		swap(permutate[index],permutate[i]);
    	}
    }
};
