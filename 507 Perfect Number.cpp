class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0)
            return false;
        
        int big = num;
        int small = 1;
        int sum = 0;
        while(small < big)
        {
            if(num % small == 0)
            {
                big = num / small;
                if(big == num)
                    big = 0;
                sum += (big + small);
            }
            
            small++;
            big = num / small;
            
        }
        return sum == num;
    }
};
