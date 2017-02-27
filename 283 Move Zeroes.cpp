class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator index = nums.begin() - 1;
        vector<int>::iterator vit = nums.begin();
        while(vit != nums.end())
        {
        	if(*vit != 0)
        	{
        		*(++index) = *vit;
        	}
        	vit++;
        }
        index++;
        while(index != nums.end())
        {
        	*(index++) = 0;
        }
    }
};