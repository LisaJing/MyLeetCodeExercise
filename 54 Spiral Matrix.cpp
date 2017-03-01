
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	vector<int> res;
        int row_size = matrix.size();
        if(row_size <= 0)
        	return res;
        int column_size = matrix[0].size();
        if(column_size <= 0)
        	return res;
        int row_start = 0;
        int column_start = 0;
        int i = row_start;
        int j = column_start;
        while(i >= row_start && i < row_size && j >= column_start && j < column_size)
        {
        	while(i >= row_start && i < row_size && j >= column_start && j < column_size)
        	{
        		res.push_back(matrix[i][j]);
        		cout <<"  ***  " <<matrix[i][j] << endl; 
        		j++;
        	}
        	cout << "i,j: "<<i << ","<<j << endl;
        	if(j == column_size)
        	{
        	    j--;
        	    i++;
        	    row_start++;
        	    column_size--;
        	}
        	
        	while(i >= row_start && i < row_size && j >= column_start )
        	{
        		res.push_back(matrix[i][j]);
        		cout <<"  ***  " <<matrix[i][j] << endl; 
        		i++;
        	}
        	if(i == row_size)
        	{
        	    i--;
        	    j--;
        	    row_size--;
        	}
        	while(i >= row_start  && j >= column_start && j < column_size)
        	{
        		res.push_back(matrix[i][j]);
        		cout <<"  ***  " <<matrix[i][j] << endl; 
        		j--;
        	}
        	if(j == column_start - 1)
        	{
        	    j++;
        	    i--;
        	    column_start++;
        	}
        	while(i >= row_start && i < row_size  && j < column_size)
        	{
        		res.push_back(matrix[i][j]);
        		cout <<"  ***  " <<matrix[i][j] << endl; 
        		i--;
        	}
        	if(i == row_start - 1)
        	{
        	    i++;
        	    j++;
        	}
        }
        return res;
    }
};