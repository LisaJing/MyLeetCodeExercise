class Solution {
public:
    int majorityElement(vector<int>& nums) {
  		int res = -1;
  		int size = 0;
  		for(std::vector<int>::iterator vit = nums.begin();vit != nums.end();vit++)
  		{
  			if(size == 0)
  			{
  				res = *vit;
  				size = 1;
  			}
  			else if(res == *vit)
  			{
  				size++;
  			}
  			else
  				size--;
  		}
  		if(checkMajorityElement(nums,res))
  			return res;
  		else
  			return -1;
    }

    bool checkMajorityElement(const std::vector<int> &nums,int target)
    {
    	int times = 0;
    	for(std::vector<int>::const_iterator vit = nums.begin();vit != nums.end();vit++)
  		{
  			if(*vit == target)
  				times++;
  		}
  		return ((times << 2) >= nums.size());
    }
};
