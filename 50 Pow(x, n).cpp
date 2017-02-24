
bool isValid = true;
class Solution {
public:
    double myPow(double x, int n) {
        if( (n < 0) && (x == 0))
        {	
        	isValid = false;
        	return -1;
        }
        	
        if(n == 0)
        {
        	if(x != 0)
        		return 1;
        	else
        	{		
        		isValid = false;
        		return -1;
        	}
        }
        if(x == 1)
        	return 1;
        if(n < 0)
        {
            if(n == INT_MIN)
				return 1.0 / (x *myPow(x,-(n + 1)));
        	return 1.0 / myPow(x,-n);
        }
        if(n == 1)
        	return x;
        if(n % 2 == 0)
        {
        	double curNum = myPow(x,n / 2);
        //	cout << "偶数 ： " << curNum << endl; 
        	return curNum * curNum;
        }
        else
        {
        	double curNum = myPow(x,(n - 1) / 2);
        //	cout << "奇数 ： " << curNum << endl;
        	return curNum * curNum * x;
        }

    }
};