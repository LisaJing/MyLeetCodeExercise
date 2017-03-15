class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map <int,int> nums1Map;
        unordered_map <int,int> nums1Nums2Map;
        for(std::vector<int>::iterator vit = nums1.begin();vit != nums1.end();vit++)
        {
        	if(nums1Map.find(*vit) == nums1Map.end())
        		nums1Map[*vit] = 1;
        }
        for(std::vector<int>::iterator vit = nums2.begin();vit != nums2.end();vit++)
        {
        	if(nums1Map.find(*vit) != nums1Map.end())
        	{
        		if(nums1Nums2Map.find(*vit) == nums1Nums2Map.end())
        		{
        			res.push_back(*vit);
        			nums1Nums2Map[*vit] = 1;
        		}	

        	}
        }
        return res;
    }
};
