
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(right < 0)
            return false;
        return searchInRotated2(nums,left,right,target);
    }
    
    bool searchInRotated2(vector<int>& nums, int left,int right,int target)
    {
        while(left <= right)
        {
        	cout << "left:" << left <<  ",right : " << right << ", target: " << target << endl;
            int mid = (left + right) / 2;
            cout << "nums[mid] : " << nums[mid] << endl; 
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid] > target)
            {
                if(nums[right] > nums[mid])
                {
                    return searchInRotated2(nums,left, mid - 1,target);
                }
                else if(nums[right] < nums[mid])
                {
                    if(nums[right] < target)
                        return searchInRotated2(nums,left,mid - 1,target);
                    else // >=
                        return searchInRotated2(nums,mid + 1,right,target);
                }
                else //==的時候
                {
                    int mark = mid;
                    while((mid != right) && (nums[mid] == nums[right]))
                    {
                        mid++;
                    }
                    if(mid == right)
                    {
                        return searchInRotated2(nums,left,mark - 1,target);
                    }
                    else
                    {
                        return searchInRotated2(nums,mid,right,target);
                    }
                }
            }
            else //nums[mid] < target
            {
                if(nums[right] > nums[mid])
                {
                	if(nums[right] >= target)
                		return searchInRotated2(nums,mid + 1,right,target);
                	else
                		return searchInRotated2(nums,left,mid - 1,target);
                    
                }
                else if(nums[right] < nums[ mid])
                {              
					return searchInRotated2(nums,mid + 1, right,target);
                }
                else
                {
                    int mark = mid;
                    
                    while((mid != right) && (nums[mid] == nums[right]))
                    {
                        mid++;
                    }
                    if(mid == right)
                    {
                        return searchInRotated2(nums,left,mark - 1,target);
                    }
                    else
                    {
                        return searchInRotated2(nums,mid,right,target);
                    }
                }
            }
        }
        return false;
    }
};
