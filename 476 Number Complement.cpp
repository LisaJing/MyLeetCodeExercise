#include <iostream>
#include <string>
#include <cstdio>
using namespace std; 

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        bool flag = false; 
        for(int i = 0;i < 32;i++)
        {
            if(num & 0x80000000)
            {
                flag = true;
                res <<= 1;
            }
            else if(flag)
            {
                unsigned int tmp = 0x1;
                
                res <<= 1;
                res |= tmp;
                
            }
            num <<= 1;
        }
        return res;
    }
};
