class Solution {
public:
    string intToRoman(int num) {
        string res;
        if(num <= 0)
        	return res;
        if(num > 3999)
        	return res;
        //处理千
        int thousands = num / 1000;
        for(int i = 0;i < thousands;i++)
        {
        	res += 'M';
        }
        res += transferNoToStr((num % 1000) / 100,100);
        res += transferNoToStr((num % 100) / 10,10);
        res += transferNoToStr(num % 10,1);
        return res;
        
    }
    
    
    string transferNoToStr(int curNum,int units)
    {
    	
    	char unitsChar;
    	char units5Char;
    	char units10Char;
    	string tmpRes;
    	if(curNum <= 0 || curNum >= 10)
    		return tmpRes;
    	switch(units)
    	{
    		case 1:
    			unitsChar = 'I';
    			units5Char = 'V';
    			units10Char = 'X';
    			break;
    		case 10:
    			unitsChar = 'X';
    			units5Char = 'L';
    			units10Char = 'C';
    			break;
    		case 100:
    			unitsChar = 'C';
    			units5Char = 'D';
    			units10Char = 'M';
    			break;
    		

    	}
    	if(curNum > 0 && curNum <= 3)
    	{
    		for(int i = 0;i < curNum;i++)
    		{
    			tmpRes += unitsChar;
    		}
    	}
    	else if(curNum <= 5)
    	{
    		int curNumOutOf5 = 5 - curNum;
    		for(int i = 0;i < curNumOutOf5;i++)
    		{
    			tmpRes += unitsChar;
    		}
    		tmpRes += units5Char;
    	}
    	else if(curNum <= 8)
    	{
    		int curNumOutOf5 = curNum - 5;
    		tmpRes += units5Char;
    		for(int i = 0;i < curNumOutOf5;i++)
    		{
    			tmpRes += unitsChar;
    		}
    		
    	}
    	else
    	{
    		tmpRes += unitsChar;
    		tmpRes += units10Char;
    	}
    	return tmpRes; 
    }
    
};
