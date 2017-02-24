class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> res;
    	int base = 1;
    	if(num >= 0)
    	{
    	    res.push_back(0);
    	    for(int i = 1;i <= num;i++)
    	    {
    		    if(is2Power(i))
    			    base = i;
    		    res.push_back(res[i % base] + 1);
    	    }
    	}

        return res;
    }

    bool is2Power(int num)
    {
    	return (num & (num - 1)) == 0;
    }
};