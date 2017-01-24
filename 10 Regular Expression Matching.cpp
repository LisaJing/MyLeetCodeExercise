class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "")
            return s == "";
        string::iterator sit = s.begin();
        string::iterator pit = p.begin();
        if((*(pit + 1)) != '*')
        {
            if(*sit == *pit  || (*sit != '\0' && (*pit == '.')))
                return isMatch(string(sit + 1,s.end()),string(pit + 1,p.end()));
            else
                return false;
        }
        else
        {
            while(*sit == *pit || (*sit != '\0' && *pit == '.' ) )
            {
                if(isMatch(string(sit,s.end()),string(pit + 2,p.end() )))
                    return true;
                
                sit++;
            }
            return isMatch(string(sit,s.end()),string(pit + 2,p.end()));
            
        }
    }
};
