class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator vit = nums.begin();
        int result = 0;
        if(nums.size() <= 0)
        {
            return result;
        }
        vector<int>::iterator vit2 = vit + 1;
        while(vit2 != nums.end())
        {
            if(*vit == *vit2)
            {
                vit2++;
            }
            else
            {
                vit++;
                *vit = *vit2;
                vit2++;
            }
        }
        result = vit - nums.begin() + 1;
        return result;
    }
};