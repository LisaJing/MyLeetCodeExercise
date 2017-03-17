class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> charmapS2T;
        unordered_map<char,char> charmapT2S;
        int sizeS = s.size();
        int sizeT = t.size();
        if(sizeS != sizeT)
            return false;
        for(int i = 0;i < sizeS;i++)
        {
            if(charmapS2T.find(s[i]) == charmapS2T.end() && charmapT2S.find(t[i]) == charmapT2S.end() )
            {
                charmapS2T[s[i]] = t[i];
                charmapT2S[t[i]] = s[i];
            }
            else if (charmapS2T.find(s[i]) == charmapS2T.end())
                return false;
            else if (charmapT2S.find(t[i]) == charmapT2S.end() )
                return false;
            else
            {
                if( (charmapS2T.find(s[i])) -> second != t[i])
                    return false;
                if( (charmapT2S.find(t[i])) -> second != s[i])
                    return false;
            }
        }
        return true;
    }
};
