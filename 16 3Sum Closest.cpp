class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDistance = 0x7fffffff;
        int minDistanceSum = 0;
        int size = nums.size();
        if(size < 3)
            return minDistanceSum;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < size - 2;i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = size - 1;
            while(left < right)
            {
                
                if(left > i + 1 && nums[left - 1] == nums[left])
                {
                    left++;
                    continue;
                }
                if(right < size - 1 && nums[right] == nums[right + 1])
                {
                    right--;
                    continue;
                }
                int curSum = nums[i] + nums[left] + nums[right];
                int curDistance = abs(curSum - target);
                
                if(curSum < target)
                {
                    left++;
                }
                else if(curSum > target)
                {
                    right--;
                }
                else
                {
                    return curSum;
                }
                
                if(curDistance < minDistance)
                {
                    minDistanceSum = curSum;
                    minDistance = curDistance;
                }
            }
        }
        return minDistanceSum;
    }
};
