class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 31;
        while(count > 0)
        {
        	count--;
        	res |= (n & 0x1);
        	res = res << 1;
        	n = n >> 1;
        	
        }
        res |= (n & 0x1);
        return res;
    }
};