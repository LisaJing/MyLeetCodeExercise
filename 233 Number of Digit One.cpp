class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
        	return 0;
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        int start = 0;
        int end = s.size() - 1;
        int index = 0;
        int res = getDigitOneNumber(s,index,end);
        return res;
    }

    int getDigitOneNumber(string s,int index,int end)
    {
    	
    	int size = end - index + 1;
    	if(size != 0)
    	{
    		if(s[index] > '9' || s[index] < '0')
    			return 0;
    	}
    	if(size == 1)
    	{
    		if(s[index] == '0')
    			return 0;
    		else
    			return 1;
    	}
    	int firstDigit1Number = 0;
    	if(s[index] > '1')
    	{
    		firstDigit1Number = power10(size - 1);
    	}
    	else if(s[index] == '1')
    	{
    		string stmp;
    		stmp.assign(s,index + 1,size - 1);
    		firstDigit1Number = atoi(stmp.c_str()) + 1;
    	}
    	cout << "firstDigit1Number:" << firstDigit1Number << endl;
    	int leftDigit = size - 2;

    	int otherDigit1Number = (s[index] - '0') * (size - 1) * power10(leftDigit);
    	cout << "otherDigit1Number:" <<otherDigit1Number << endl;
    	int leftGetDigitOneNumber = getDigitOneNumber(s,index + 1,end);
    	cout << "leftGetDigitOneNumber:" << leftGetDigitOneNumber;
    	return firstDigit1Number + otherDigit1Number + leftGetDigitOneNumber;

    }
    int power10(int n)
    {
    	
    	int res = 1;
    	for(int i = 0;i < n;i++)
    	{
    		res *= 10;
    	}
    	return res;
    }
};
