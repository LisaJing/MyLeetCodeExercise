class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> numMap;
        
        std::vector<int>::iterator vit = nums.begin();
        while(vit != nums.end())
        {
        	unordered_map<int,int>::iterator  uit = numMap.find(*vit);
        	if(uit == numMap.end())
        	{
        		numMap[*vit] = 1;
        	}
        	else
        	{
        		return true;
        	}
        	vit++;
        }
        return false;
    }
};
