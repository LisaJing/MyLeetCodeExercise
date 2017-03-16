class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        std::vector<std::vector<int> > res;
        if (size <= 0)
        {
        	return res;
        }
        for(int i = 0;i < size;i++)
        {
        	std::swap(nums[0],nums[i]);
        	getPermutation(nums,1,res);
        	std::swap(nums[0],nums[i]);
        }
        return res;
    }


    void getPermutation(std::vector<int> &nums,int index,std::vector<std::vector<int> > &res)
    {
    	int size = nums.size();
    	if(index == size)
    	{
    		res.push_back(nums);
    		return ;
    	}
    	for(int i = index;i < size;i++)
    	{
    		
    		std::swap(nums[index],nums[i]);
        	getPermutation(nums,index + 1,res);
        	std::swap(nums[index],nums[i]);
    	}
    }
};
