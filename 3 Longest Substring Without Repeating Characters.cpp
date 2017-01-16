class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> recentCharIndex;
        int size = s.size();
        int maxSubLen = 0;
        int curLen = 0;
        for(int i = 0;i < size;i++)
        {
            unordered_map<char, int>::iterator uit = recentCharIndex.find(s[i]);
            
            if(uit == recentCharIndex.end())
            {
                recentCharIndex[s[i]] = i;
                curLen = curLen + 1;
            }
            else
            {
                curLen = min(curLen + 1,i - uit -> second);
                recentCharIndex[s[i]] = i;
            }
            
            if(maxSubLen < curLen)
            {
                maxSubLen = curLen;
            }
        }
        return maxSubLen;
    }
};