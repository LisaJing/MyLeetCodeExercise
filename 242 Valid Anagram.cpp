class Solution {
public:
    bool isAnagram(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        if(sizeS != sizeT)
        	return false;
       
        int sMap[256];
        for(int i = 0;i < 256;i++)
        {
        	sMap[i] = 0;
        }
        
        for(int i = 0;i < sizeS;i++)
        {
        	sMap[s[i]]++;
        }
        for(int i = 0;i < sizeT;i++)
        {
        	sMap[t[i]]--;
        	if(sMap[t[i]] < 0)
        	{
        		return false;
        	}
        }

        return true;
    }
};
