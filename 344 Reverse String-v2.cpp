class Solution {
public:
    string reverseString(string s) {
        string::iterator sit1 = s.begin();
        string::iterator sit2 = s.end() - 1;
        while(sit1 < sit2)
        {
        	char tmp = *sit1;
        	*sit1 = *sit2;
        	*sit2 = tmp;
        	sit1++;
        	sit2--;
        }
        return s;
    }
};