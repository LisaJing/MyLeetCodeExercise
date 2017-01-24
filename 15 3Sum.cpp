class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int size = nums.size();
        if(size < 3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < size - 2;i++)
        {
            if(i > 0  && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = size - 1;
            while(left < right)
            {
                if(left > i + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }
                if(right < size - 1 && nums[right] == nums[right + 1])
                {
                    right--;
                    continue;
                }
                if(nums[left] + nums[right] == -nums[i])
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] < -nums[i])
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
