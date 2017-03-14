class Solution {
public:
    string convertToBase7(int num) {
        string res;
        string restmp;
        if(num == 0)
        {
        	res = '0';
        	return res;
        }
        if(num < 0)
        {
        	res = '-';
        	num = -num;
        }

        while(num != 0)
        {
        	int tmp = num % 7;
        	num /= 7;
        	char ctmp = '0' + tmp;
        	restmp += ctmp;
        }
        reverse(restmp.begin(),restmp.end());
        res += restmp;
        return res;

    }
};
