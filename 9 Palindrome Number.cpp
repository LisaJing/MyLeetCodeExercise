class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int y = 0;
        int tmp = x;
        while(tmp != 0)
        {
            y *= 10;
            y += tmp % 10;
            tmp /= 10;
        }
        return x == y;
    }
};