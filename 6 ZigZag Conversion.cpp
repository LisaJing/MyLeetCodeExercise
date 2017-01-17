class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(numRows <= 0 || s == "")
            return res;
        if(numRows == 1)
            return s;
        string strArray[numRows];
        int size = s.size();
        int i = 0;
        int curLoc = 0;
        
        while(i < size)
        {
            
            while(i < size && curLoc >= 0 && curLoc < numRows)
            {
                strArray[curLoc] += s[i];
                curLoc++;
                i++;
            }
            curLoc -= 2;
            while(i < size && curLoc >= 0 && curLoc < numRows)
            {
                
                strArray[curLoc] += s[i];
                curLoc--;
                i++;
            }
            curLoc += 2;
            
        }
        for(int i = 0;i < numRows;i++)
        {
            res += strArray[i];
        }
        return res;
    }
};