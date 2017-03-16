class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	std::vector<std::vector<int> > res;
        int size = nums.size();
        if(size <= 0)
        	return res;
        sort(nums.begin(),nums.end());
        getPermutationUnique(nums,0,res,size);
        return res;
    }

    void getPermutationUnique(std::vector<int> nums,int index,std::vector<std::vector<int> > & res,int size)
    {
    	
    	if(index == size - 1)
    	{
    		res.push_back(nums);
    		return;
    	}
    	for(int i = index;i < size;i++)
    	{
    		if((index != i ) && (nums[index] == nums[i]) )
    			continue;
    		std::swap(nums[index],nums[i]);
    		getPermutationUnique(nums,index + 1,res,size);
    	}
    }
};
