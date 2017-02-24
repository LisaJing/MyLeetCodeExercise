class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> res;
        if(size <= 0)
        	return res;
        int xorRes = nums[0];
        for(int i = 1;i < size;i++)
        	xorRes ^= nums[i];
        int i = 0;
        for(;i < 32;i++)
        {
        	if((xorRes >> i) & 0x1 == 1)
        		break;
        }
        std::vector<int> nums1;
        std::vector<int> nums2;
        for(int j = 0;j < size;j++)
        {
        	if((nums[j] >> i) & 0x1 == 1)
        		nums1.push_back(nums[j]);
        	else
        		nums2.push_back(nums[j]);
        }

        int size1 = nums1.size();
        int size2 = nums2.size();
        int res1 = 0;
        int res2 = 0;
        for(int i = 0;i < size1;i++)
        	res1 ^= nums1[i];
        for(int i = 0;i < size2;i++)
        	res2 ^= nums2[i];
        res.push_back(res1);
        res.push_back(res2);
        return res;

    }
};