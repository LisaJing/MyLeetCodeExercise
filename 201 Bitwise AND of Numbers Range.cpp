class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int offset = 0;
        while(m != n)
        {
        	m = m >> 1;
        	n = n >> 1;
        	offset++;
        }
        res = m << offset;
        return res;
    }
};