class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        return (log10(n)/log10(3) - int(log10(n)/log10(3)) == 0);
    }
};