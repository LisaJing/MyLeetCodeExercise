class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map <int,int> nums1Map;
        for(std::vector<int>::iterator vit = nums1.begin();vit != nums1.end();vit++)
        {
        	if(nums1Map.find(*vit) == nums1Map.end())
        		nums1Map[*vit] = 1;
        	else
        	    nums1Map[*vit]++;
        }
        for(std::vector<int>::iterator vit = nums2.begin();vit != nums2.end();vit++)
        {
        	if(nums1Map.find(*vit) != nums1Map.end())
        	{
        	    res.push_back(*vit);
                nums1Map[*vit]--;
                if(nums1Map[*vit] == 0)
                    nums1Map.erase(*vit);
        	}
        }
        return res;
    
    }
};
