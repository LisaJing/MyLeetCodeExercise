class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        std::vector<int> res;
        if(pSize <= 0 || sSize <= 0)
            return res;
        string::iterator sit = s.begin();
        
        while(s.end() - sit  >= pSize)
        {
            string stmp(sit,sit + pSize);
            if(isAnagram(stmp,p))
            {
                res.push_back(sit - s.begin());
            }
            sit++;
        }
        return res;
    }
    
    bool isAnagram(string s, string t) {
        //cout << "s:" << s << endl;
        //cout << "t:" << t << endl;
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
