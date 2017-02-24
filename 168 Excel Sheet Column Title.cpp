class Solution {
public:
    string convertToTitle(int n) {
        string res_tmp;
        if(n <= 0)
            return res_tmp;
        
        while(n > 26)
        {
            n--;
            res_tmp += (n % 26) + 'A';
            n = n / 26;
        }
        n--;
        res_tmp += n + 'A';
        string res(res_tmp.rbegin(),res_tmp.rend());
		return res;
    }
};