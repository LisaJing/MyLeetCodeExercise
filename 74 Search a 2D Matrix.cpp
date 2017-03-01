class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row_size = matrix.size();
        if(row_size <= 0)
        	return false;
        int column_size = matrix[0].size();
        if(column_size <= 0)
        	return false;
      
        int total_size =row_size * column_size;
        int left = 0;
        int right = total_size - 1;
        while(left <= right)
        {
        	int mid = (left + right) / 2;
    
        	if(matrix[mid / column_size][mid % column_size] == target)
        		return true;
        	else if(matrix[mid / column_size][mid % column_size] < target)
        		left = mid + 1;
        	else 
        		right = mid - 1;
        }
        return false;
    }
};