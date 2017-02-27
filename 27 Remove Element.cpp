class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if(size <= 0)
            return 0;
        
        int index = 0;
        int i = index;
        while(i < size)
        {
            if(nums[i] != val)
            {
                nums[index++] = nums[i++];
            }
            else
            {
                i++;
            }
        }
        return index;
    }
};