class Solution {
public:
    string countAndSay(int n) {
    	string s;
    	s.clear();
    	string res;
    	res.clear();
        if(n <= 0)
        	return s;
        s = "1";
        if(n == 1)
        	return s;
        while(n > 1)
        {
        	string::iterator sit = s.begin();
        	while(sit != s.end())
        	{
        		int count = 1;
        		char curChar = *sit;
        		while(sit + 1 != s.end() && (*sit == *(sit + 1) ))
        		{
        			count++;
        			sit++;
        		}
        		stringstream ss;
        		ss.clear();
        		string numstr;
        		numstr.clear();
        		ss << count;
        		ss >> numstr;
        		res += numstr;
        		res += curChar;
        		sit++;
        	}
        //	cout << res << endl;
        	
        	s = res;
        	res.clear();
        
        	
        	n--;

        }
        return s; 
    }
};
