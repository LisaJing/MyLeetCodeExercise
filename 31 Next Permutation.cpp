class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int leftIndex = 0;
        int rightIndex = size - 1;
        while((leftIndex <= rightIndex) && (nums[rightIndex - 1] >= nums[rightIndex]) )  
        //从右至左找到第一个违背递增的数，作为partion数
        {
           rightIndex--;
        }
        rightIndex--;
        if(rightIndex < leftIndex) 
        {
            sort(nums.begin(),nums.end());
        }
        else
        {
            int changeNumberIndex = size - 1;
            while( (changeNumberIndex >= 0 ) && (nums[changeNumberIndex] <= nums[rightIndex]) )
            {
                changeNumberIndex--;
            }
            if(changeNumberIndex >= 0)
            {
                std::swap(nums[rightIndex],nums[changeNumberIndex]);
                getNumsReverse(nums,rightIndex + 1);
            }

        }
        
    }

    void getNumsReverse(vector<int>& nums,int i)
    {
        int size = nums.size();
        int left = i;
        int right = size - 1;
        while(left < right)
        {
            std::swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    
};