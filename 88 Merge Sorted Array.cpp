class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total_size = m + n;
        int curIndex = total_size - 1;
        
        int index1 = m - 1;
        int index2 = n - 1;
        while(index1 >= 0 && index2 >= 0)
        {
        	if(nums1[index1] > nums2[index2])
        	{
        		nums1[curIndex] = nums1[index1];
        		index1--;
        		curIndex--;
        	}
        	else
        	{
        		nums1[curIndex] = nums2[index2];
        		index2--;
        		curIndex--;
        	}
        }
        while(index2 >= 0)
           	nums1[curIndex--] = nums2[index2--];
    }
};