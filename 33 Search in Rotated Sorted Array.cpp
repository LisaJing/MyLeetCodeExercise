
 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(right < 0)
        {
            return -1;
        }
        
        int res = searchInRotated(nums,left,right,target);
        return res;
    }
    
    int searchInRotated(vector<int>& nums,int left,int right,int target)
    {
    	//cout<<"left:"<<left<<",  right: "<<right << ",target:" << target <<endl;
		while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                if(nums[right] > nums[mid])
                {
                    if(nums[right] >= target)
                    {
                        return searchInRotated(nums,mid + 1, right, target);
                    }
                    else
                    {
                        return searchInRotated(nums,left, mid - 1, target);
                    }
                }
                else
                {
                    return searchInRotated(nums,mid + 1, right, target);
                }
            }
            else
            {
                if(nums[right] > nums[mid])
                {
                    return searchInRotated(nums,left, mid - 1, target);
                }
                else
                {
                    if(nums[right] >= target)
                    {
                        return searchInRotated(nums,mid + 1, right, target);
                    }
                    else
                    {
                        return searchInRotated(nums,left, mid - 1, target);
                    }

                }
            }
        }
        return -1;
    }
};