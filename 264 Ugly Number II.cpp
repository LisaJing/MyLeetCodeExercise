class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 1)
        	return n;
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        std::vector<int>::iterator vit2 = uglyNums.begin();
        std::vector<int>::iterator vit3 = uglyNums.begin();
        std::vector<int>::iterator vit5 = uglyNums.begin();
        
        for(int i = 1;i < n;i++)
        {
        	int curNum = min3Num(*vit2 * 2,*vit3 * 3,*vit5 * 5);
        	uglyNums[i] = curNum;
        	if(curNum >= *vit2 * 2)
        		vit2++;
        	if(curNum >= *vit3 * 3)
        		vit3++;
        	if(curNum >= *vit5 * 5)
        		vit5++;	
        }
        return uglyNums[n - 1];
    }

    int min3Num(int a,int b,int c)
    {
    	return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }
};
