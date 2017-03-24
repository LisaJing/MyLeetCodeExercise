class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> psMap;
        unordered_map<string,char> spMap;
        int pSize = pattern.size();
        int sSize = str.size();
        if((pSize == 0 && sSize != 0) || (pSize != 0 && sSize == 0) )
        	return false;
        int spaceLoc = 0;
        
        for(int i = 0;i < pSize;i++)
        {
            cout <<"i:"<< i << endl;
        	int curLoc = str.find(" ",spaceLoc);
        	cout << "curLoc:" << curLoc << endl;
        	if(i == pSize - 1 && curLoc != string::npos)
             return false;
        	else if(curLoc == string::npos && i != pSize - 1)
        		return false;
        	string curStr(str,spaceLoc,curLoc - spaceLoc);
        	spaceLoc = curLoc + 1;
        	unordered_map<char,string>::iterator psit = psMap.find(pattern[i]);
        	unordered_map<string,char>::iterator spit = spMap.find(curStr);
        	if( (psit != psMap.end() && spit == spMap.end()) || (psit == psMap.end() && spit != spMap.end()) )
        		return false;
        
        	if(psit == psMap.end())
        	{
        	    cout << "("<<pattern[i]<<","<< curStr<<")"<<endl;
        		psMap[pattern[i]] = curStr;
        		spMap[curStr] = pattern[i];
        	}
        	else
        	{
        		if((psMap[pattern[i]] != curStr) || (spMap[curStr] != pattern[i]) )
              return false;
        	}
        } 
        return true;
    }
};
