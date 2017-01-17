class Solution {
public:
    int myAtoi(string str) {
        string::iterator sit = str.begin();
        long long num = 0;
        bool positive = true;
        while(sit != str.end())
        {
            while(*sit == ' ' || *sit == '\t') //处理空字符
                sit++;
            if(*sit == '-')
            {
                positive = false;
                sit++;
            }
            else if(*sit == '+')
            {
                positive = true;
                sit++;
            }
            
            while(isDigit(*sit))
            {
                num *= 10;
                num += (*sit - '0');
                sit++;
                long long  curSum = num * (positive ? 1 : -1);
                cout << curSum << endl;
                if(curSum > INT_MAX)
                    return INT_MAX;
                if(curSum < INT_MIN)
                    return INT_MIN;
            }
            
            return num * (positive ? 1 : -1);
            
            
        }
        return int(num);
    }
    
    bool isDigit(char c)
    {
        return (c >= '0')&&(c <= '9');
    }
};