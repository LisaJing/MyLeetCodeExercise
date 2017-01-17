class Solution {
public:
    int reverse(int x) {
        long long tmpx = x;
        long long tmpy = 0;
        bool positive = true;
        if(x < 0)
            positive = false;
        while(tmpx != 0)
        {
            tmpy *= 10;
            tmpy += abs(tmpx % 10);
            tmpx /= 10;
            long long curSum = tmpy * (positive ? 1 : -1);
            if(curSum  >= INT_MAX)
                return 0;
            if(curSum <= INT_MIN)
                return 0;
        }
        int y = (int)(tmpy * (positive ? 1 : -1));
        
        return y;
    }
};