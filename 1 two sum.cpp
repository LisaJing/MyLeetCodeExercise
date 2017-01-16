struct Num_Index
{
    int num;
    int index;
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int size = nums.size();
        vector<Num_Index> num_index(size);
        for(int i = 0;i < size;i++)
        {
            num_index[i].index = i;
            num_index[i].num = nums[i];
        }
        sort(num_index.begin(),num_index.end(),compareNum);
        int left = 0;
        int right = size - 1;
        while(left < right)
        {
            if(num_index[left].num + num_index[right].num < target)
                left++;
            else if(num_index[left].num + num_index[right].num > target)
                right--;
            else
            {
                res.push_back(num_index[left].index);
                res.push_back(num_index[right].index);
                sort(res.begin(),res.end());
                return res;
            }
        
        }
        return res;
    }
    static bool compareNum(Num_Index a, Num_Index b)
    {
        return a.num < b.num;
    }
};