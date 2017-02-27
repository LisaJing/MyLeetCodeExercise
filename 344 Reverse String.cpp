class Solution {
public:
    string reverseString(string s) {
        string res(s.rbegin(),s.rend());
        return res;
    }
};