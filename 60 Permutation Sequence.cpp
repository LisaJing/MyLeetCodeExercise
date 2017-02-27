class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n,'0');
        if(n <= 0)
        {
            return s;
        }
        for(int i = 1;i <= n;i++)
        {
            s[i - 1] += i;
        }
        string stmp(s);
        string res;
        k--;
        
        for(int i = n;i > 0;i--)
        {
            int base = getFactorial(i - 1);
            int curNum = k / base;
            res.push_back(stmp[curNum]);
            stmp.erase(curNum,1);
            k = k % base;
        }
        return res;
    }
    
    int getFactorial(int n)
    {
        int res = 1;
        for(int i = 1;i <= n;i++)
        {
            res *= i;
        }
        return res;
    }
};