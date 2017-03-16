class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	std::vector<int> res(rowIndex + 1);
    	std::vector<int> res2(rowIndex + 1);
        if(rowIndex < 0)
        	return res;
        
        res[0] = 1;
        res2[0] = 1;
        res[rowIndex] = 1;
        res2[rowIndex] = 1;
        for(int i = 1;i < rowIndex;i++)
        {
        	res[i] = 0;
        	res2[i] = 0;
        }
        int j = 1;
        for(;j <= rowIndex;j++)
        {
        	for(int i = 1;i < rowIndex;i++)
        	{
        		res[i] = res2[i - 1] + res2[i];
        		cout <<"i:"<<i <<",res[i]"<< res[i]<<endl;
        	}
        	if(j != rowIndex)
        	    swap(res,res2);
        }

        return res;
    }
};
