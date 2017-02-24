class Solution {
public:
    int titleToNumber(string s) {
        string::iterator sit = s.begin();
        int res = 0;
        while(sit != s.end())
        {
            res *= 26;
            res += (*sit - 'A' + 1);
            sit++;
        }
        return res;
    }
};