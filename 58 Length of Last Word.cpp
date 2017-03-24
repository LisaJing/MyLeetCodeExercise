class Solution {
public:
    int lengthOfLastWord(string s) {
        int loc = s.find_last_of(" ");
        int curSize = s.size();
        if(curSize <= 0)
            return 0;
        while(curSize > 0 && loc == curSize - 1)
        {
            cout << "loc:" << loc << endl;
            string stmp(s,0,loc);
            s = stmp;
            curSize--;
            if(loc == string::npos)
                return curSize;
            loc = stmp.find_last_of(" ");
        }
        if(loc == string::npos)
            return curSize;
        else
            return curSize - 1 - loc;
        
    }
};
