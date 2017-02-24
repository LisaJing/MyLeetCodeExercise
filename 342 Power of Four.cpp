class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
        	return false;
        if((num & (num - 1)) == 0)
        {
        	int _0_num = calculate0Num(num);
        	if(_0_num % 2 == 0)
        		return true;
        	else
        		return false;
        }
        else
        	return false;
        
    }
    int calculate0Num(int num)
    {
    	int count = 0;
    	while((num & 0x1) != 1)
    	{
    		num = num >> 1;
    		count++;
    	}
    	return count;
    }
};