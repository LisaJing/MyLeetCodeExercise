class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> tmp(n,0);
        vector<vector<int> > res(n,tmp);
        if(n <= 0)
            return res;
        int row_start = 0;
        int column_start = 0;
        int row_size = n;
        int column_size = n;
        int i = row_start;
        int j = column_start;
        int count = 0;
        while(j >= column_start && j < column_size && i >= row_start && i < row_size)
        {
        	while(j < column_size && i >= row_start && i < row_size)  //left
        	{
        		res[i][j] = ++count;
        		j++;
        	}
        	j--;
        	i++;
        	column_size--;
        	row_start++;
        	while(j >= column_start  && i >= row_start && i < row_size)//down
        	{
        		res[i][j] = ++count;
        		i++;
        	}
        	i--;
        	j--;
        	row_size--;
        	while(j >= column_start && j < column_size && i >= row_start)//right
        	{
        		res[i][j] = ++count;
        		j--;
        	}
        	j++;
        	i--;
        	column_start++;
        	while(j < column_size && i >= row_start && i < row_size) //up
        	{
        		res[i][j] = ++count;
        		i--;
        	}
        	i++;
        	j++;
        	
        }
        return res;
    }
};