class Solution {
public:
    string addBinary(string a, string b) {
        int sizeA = a.size();
        int sizeB = b.size();
        if(sizeA <= 0)
        	return b;
        if(sizeB <= 0)
        	return a;
        string res_copy;
        string::iterator ait = a.end() - 1;
        string::iterator bit = b.end() - 1;
        bool add_one = false;
        while(ait != a.begin() - 1 || bit != b.begin() - 1 || add_one)
        {
        	char curA = (ait != a.begin() - 1) ? *ait : '0';
        	char curB = (bit != b.begin() - 1) ? *bit : '0';
        	if(ait != a.begin() - 1)
        	    ait--;
        	if(bit != b.begin() - 1)
        	    bit--;
        	if(curA == '1' && curB == '1')
        	{
        		if(add_one)
        		{
        			add_one = true;
        			res_copy += '1';
        		}
        		else
        		{
        			add_one = true;
        			res_copy += '0';
        		}
        	}
        	else if(curA == '0' && curB == '0')
        	{
        		if(add_one)
        		{
        			add_one = false;
        			res_copy += '1';
        		}
        		else
        		{
        			add_one = false;
        			res_copy += '0';
        		}
        	}
        	else
        	{
        		if(add_one)
        		{
        			add_one = true;
        			res_copy += '0';
        		}
        		else
        		{
        			add_one = false;
        			res_copy += '1';
        		}
        	}
        }
        reverse(res_copy.begin(),res_copy.end());
        return res_copy;
    }
};