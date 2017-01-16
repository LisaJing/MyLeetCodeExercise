class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalsize = size1 + size2;
        if(totalsize & 0x1)
            return findKthNum(nums1,0,size1,nums2,0,size2,totalsize / 2 + 1);
        else
            return (findKthNum(nums1,0,size1,nums2,0,size2,totalsize / 2 ) + findKthNum(nums1,0,size1,nums2,0,size2,totalsize / 2 + 1)) / 2.0;
    }
    
    double findKthNum(vector<int>& nums1, int start1,int size1,vector<int>& nums2,int start2,int size2,int k)
    {
        if(size1 < size2)
            return findKthNum(nums2,start2,size2,nums1,start1,size1,k);
        if(size2 == 0)
            return nums1[k - 1];
        if(k == 1)
            return min(nums1[start1],nums2[start2]);
        int k2 = min(k / 2,size2);
        int k1 = k - k2;
        if(nums1[start1 + k1 - 1] < nums2[start2 + k2 - 1])
            return findKthNum(nums1,start1 + k1,size1 - k1,nums2,start2,size2,k - k1);
        else if(nums1[start1 + k1 - 1] > nums2[start2 + k2 - 1])
            return findKthNum(nums1,start1,size1,nums2,start2 + k2,size2 - k2,k - k2);
        else
            return nums1[start1 + k1 - 1];
    }
    
};