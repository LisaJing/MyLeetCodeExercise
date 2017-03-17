class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> strmap(26,0);
        for(string::iterator sit = s.begin();sit != s.end();sit++)
        {
            strmap[*sit - 'a']++;
        }
        for(string::iterator tit = t.begin();tit != t.end();tit++)
        {
            strmap[*tit - 'a']--;
        }
        for(int i = 0;i < 26;i++)
        {
            if(strmap[i] < 0)
                return 'a' + i;
        }
        return ' ';
    }
};
