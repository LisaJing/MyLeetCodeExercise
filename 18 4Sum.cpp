class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        vector<int> tmp(4);
        unordered_multimap<int,pair<int,int> > sumIndexPair;
        int size = nums.size();
        if(size < 4)
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < size -  1;i++)
        {
            for(int j = i + 1;j < size;j++)
            {
                int sum = nums[i] + nums[j];
                sumIndexPair.insert(make_pair(sum,make_pair(i,j) ) );
            }
        }
        typedef unordered_multimap<int,pair<int,int> >::iterator Iterator;
        Iterator twosum1 = sumIndexPair.begin();
        for(; twosum1 != sumIndexPair.end();twosum1++ )
        {
            pair<Iterator,Iterator> findRange = sumIndexPair.equal_range(target - twosum1 -> first);
            for(Iterator i = findRange.first;i != findRange.second;i++)
            {
                int index1 = (twosum1 -> second).first;
                int index2 = (twosum1 -> second).second;
                int index3 = (i -> second).first;
                int index4 = (i -> second).second;
                int no1 = nums[index1];
                int no2 = nums[index2];
                int no3 = nums[index3];
                int no4 = nums[index4];
                if((index1 != index3) && (index1 != index4) && (index2 != index3) && (index2 != index4) )
                {
                    tmp[0] = no1;
                    tmp[1] = no2;
                    tmp[2] = no3;
                    tmp[3] = no4;
                    sort(tmp.begin(),tmp.end());
                    res.push_back(tmp);
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end() );
        return res;
    }
};