class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> numLoc;
        int size = nums.size();
        if(size <= 0)
            return false;
        for(int i = 0;i < size;i++)
        {
            unordered_map<int,int>::iterator uit = numLoc.find(nums[i]);
            if(uit == numLoc.end())
            {
                numLoc[nums[i]] = i;
            }
            else
            {
                int distance = i - uit -> second ;
                if(distance <= k)
                    return true;
                else
                {
                    numLoc.erase(nums[i]);
                    numLoc[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
