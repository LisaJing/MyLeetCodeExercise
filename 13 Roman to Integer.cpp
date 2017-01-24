class Solution {
public:
	Solution()
	{
		nextChar['M'] = 'C'; //900
		nextChar['D'] = 'C'; //400
		nextChar['C'] = 'X'; //90
		nextChar['L'] = 'X'; //40
		nextChar['X'] = 'I'; //9
		nextChar['V'] = 'I'; //4
		curNum['M'] = 1000;
		curNum['D'] = 500;
		curNum['C'] = 100;
		curNum['L'] = 50;
		curNum['X'] = 10;
		curNum['V'] = 5;
		curNum['I'] = 1;
	}

    int romanToInt(string s) {
        int res = 0;
        int size = s.size();
        if(size <= 0)
        	return res;
        string::iterator sit = s.begin();
        bool flag = false;
        while(sit != s.end())
        {

        	if(*(sit + 1) != '\0' )
        	{
        		if(nextChar[*(sit + 1)] == *sit)
        		{
        			res += curNum[*(sit + 1)] - curNum[*sit];
        			sit += 2;
        		}
        		else
        		{
        			res += curNum[*sit];
        			sit++;
        		}
        	}
        	else
        	{
        		flag = true;
        		break;
			}
        }
        res += curNum[*sit];
        return res;
    }

private:
	map<char,char> nextChar;
	map<char,int> curNum;

};
