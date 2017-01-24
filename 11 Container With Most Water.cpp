/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size <= 0)
        	return 0;
        int leftIndex = 0;
        int rightIndex = size - 1;
        int maxArea = 0;
        int curArea = 0;
        while(leftIndex < rightIndex)
        {
        	curArea = (rightIndex - leftIndex) * std::min(height[rightIndex],height[leftIndex]);
        	if(maxArea < curArea)
        	{
        		maxArea = curArea;
        	}
        	height[leftIndex] < height[rightIndex] ? leftIndex++:rightIndex--;

        }
        return maxArea;
    }
};
