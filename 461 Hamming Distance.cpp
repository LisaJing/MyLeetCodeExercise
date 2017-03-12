class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff_XY = x ^ y;
        int count = 0;
        while(diff_XY != 0)
        {
            count++;
            diff_XY = diff_XY & (diff_XY - 1);
        }
        return count;
    }
};
