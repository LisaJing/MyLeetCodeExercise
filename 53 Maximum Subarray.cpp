class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size <= 0)
            return 0;
        int maxSum = nums[0];
        int curSum = nums[0];
        for(int i = 1;i < size;i++)
        {
            if(curSum < 0)
            {
                curSum = nums[i];
            }
            else
            {
                curSum += nums[i];
               
            }
            if(curSum >= maxSum)
            {
                maxSum = curSum;
            }
        }
        return maxSum;
        
    }
};
