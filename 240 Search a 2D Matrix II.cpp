class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        if(row_size <= 0)
        	return false;
        int column_size = matrix[0].size();
        if(column_size <= 0)
        	return false;
        int i = column_size - 1;
        int j = 0;
        while(i >= 0 && j < row_size)
        {
        	if(matrix[j][i] == target)
        		return true;
        	else if(matrix[j][i] < target)
        		j++;
        	else if(matrix[j][i] > target)
        		i--;
        }
        return false;
    }
};