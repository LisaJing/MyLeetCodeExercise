static bool compareCombination(int a,int b)
    {
    	stringstream ssTmp;
    	string aStr;
    	string bStr;
    	ssTmp << a;
    	ssTmp >> aStr;
    	ssTmp.clear();
    	ssTmp << b;
    	ssTmp >> bStr;
    	string sResAB = aStr + bStr;
    	string sResBA = bStr + aStr;
    	return sResAB > sResBA;
    }



class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	string res;
        int size = nums.size();
        if(size <= 0)
        	return res;
        sort(nums.begin(),nums.end(),compareCombination);
        for(std::vector<int>::iterator vit = nums.begin();vit != nums.end();vit++)
        {
        	stringstream ssTmp;
        	ssTmp.clear();
        	ssTmp << *vit;
        	string tmp;
        	ssTmp >> tmp;
        	res += tmp;
        	if((vit == nums.begin()) && (*vit == 0))
        	    return res;
        }
        return res;

    }
   
};
