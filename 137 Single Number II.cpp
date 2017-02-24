class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitsOfNum[32];
        for(int i = 0;i < 32;i++)
        {
        	bitsOfNum[i] = 0;
		}
        int size = nums.size();
        for(int i = 0;i < size;i++)
        {
        	cout << nums[i] << endl;
        	for(int j = 0;j < 32;j++)
        	{
        		bitsOfNum[j] += (0x1 & nums[i]);
        		nums[i] = nums[i] >> 1;
        	}
        }
        int res = 0;
        for(int i = 0;i < 32;i++)
        {
        	res += (bitsOfNum[i] % 3) << i; 	
        }
        return res;
    }
    
};