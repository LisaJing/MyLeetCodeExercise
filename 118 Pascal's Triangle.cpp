class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	std::vector<std::vector<int> > res;
    	if(numRows <= 0)
    		return res;
    	
        for(int i = 1;i <= numRows;i++)
        {
        	std::vector<int> tmp(i);
        	tmp[0] = 1;
        	cout << tmp[0] <<"\t"<< endl;
        	tmp[i - 1] = 1;
        	for(int j = 1;j < i - 1;j++)
        	{
        		tmp[j] = res[i - 1 - 1][j - 1] + res[i - 1- 1][j];
        	}
        	res.push_back(tmp);
        }
        return res;
    }
};

