class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size <= 2)
            return 0;
        int curHeight = 0;
        vector<int> leftMax(size,0);
        vector<int> rightMax(size,0);

        for(int i = 0;i < size;i++)
        {
            leftMax[i] = curHeight;
            curHeight = std::max(curHeight,height[i]);
        }
        curHeight = 0;
        for(int i = size - 1;i >= 0;i--)
        {
            rightMax[i] = curHeight;
            curHeight = std::max(curHeight,height[i]);
        }
        int totalWater = 0;
        for(int i = 0;i < size;i++)
        {
            int curWaterHeight = (std::min(leftMax[i],rightMax[i]) - height[i] );
             totalWater += (curWaterHeight >= 0 ? curWaterHeight : 0);
        }
        return totalWater;

    }
};