class Solution {
public:
    string longestPalindrome(string s) {
    	string res;
    	int res_len = 0;
        int size = s.size();
        if(size <= 0)
        	return res;
        string::iterator sit = s.begin();
        string curSubStr;
        int curSubLen = 0;
        while(sit != s.end())
        {
        	curSubLen = getcurSubStr(s,sit,curSubStr);
        	//cout <<"curSubLen:" << curSubLen << endl; 
        	if(curSubLen > res_len)
        	{
        		res = curSubStr;
        		res_len = curSubLen;
        		//cout << "res:" << res << endl;
        	}
        	sit++;
        }
        return res;
    }

    int getcurSubStr(string &s,string::iterator sit,string &curSubStr)
    {
    	string::iterator sleft= sit - 1;
    	string::iterator sright = sit + 1;
    	int curSubLenOdd = 1;
    	int curSubLenEven = 0;
    	string curSubStrOdd;
    	curSubStrOdd.assign(sit, sit + 1);
    	string curSubStrEven;
    	int curSubLen = 0;
    	
    	while(sleft != s.begin() - 1  && sright != s.end())  
    	{
    		if(*sleft == *sright)
    		{
    			
    			curSubLenOdd += 2;
    			curSubStrOdd.assign(sleft,sright + 1);
    			sleft--;
    			sright++;
    		}
    		else
    			break;
    	}
    	sleft= sit - 1;
    	sright = sit + 1;
    	if(sright != s.end() && *sright == *sit)
    	{
    	    curSubStrEven.assign(sit,sright + 1);
    		sright++;
    		curSubLenEven = 2;
    		while(sleft != s.begin() - 1  && sright != s.end())  
    		{
    			if(*sleft == *sright)
    			{
    				
    				curSubLenEven += 2;
    				curSubStrEven.assign(sleft,sright + 1);
    				sleft--;
    				sright++;
    			}
    			else
    				break;
    		}
    	}
		//cout << "奇数" << curSubStrOdd << endl; 
		//cout << "偶数" << curSubStrEven << endl; 
    	if(curSubLenEven > curSubLenOdd)
    	{
    		curSubLen = curSubLenEven;
    		curSubStr = curSubStrEven;
    	}
    	else
    	{
    		curSubLen = curSubLenOdd;
    		curSubStr = curSubStrOdd;
    	} 
    	return curSubLen;
    }
};