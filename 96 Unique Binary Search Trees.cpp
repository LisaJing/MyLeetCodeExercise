class Solution {
public:
    int numTrees(int n) {
    	if(n < 0)
    		return 0;
    	int res[n + 1];
    	res[0] = 1;
        for(int i = 1;i <= n;i++)
        {
        	res[i] = 0;
        	for(int k = 0;k < i;k++)
        	{
        		res[i] += res[k] * res[i - 1 - k];
        	}
        }
        return res[n];
    }
};
