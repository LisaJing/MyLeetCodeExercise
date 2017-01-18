#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        cout << "size: " << size <<endl;
        string res;
        if(size <= 0)
            return res;
        if(size == 1)
            return strs[0];
        
        vector<string::iterator> sits(size);
        for(int i = 0;i < size;i++)
        {
            sits[i] = (strs[i]).begin();
        }
        int resLen = 0;
        bool sameChar = true;
        while(sameChar)
        {
            if(*(sits[0]) == '\0')
            {
                sameChar = false;
                break;
            }
            for(int i = 1;i < size;i++)
            {
                if(*(sits[i]) != '\0' && *(sits[i]) != *(sits[i - 1]))
                {
                    sameChar = false;
                    break;
                }
                else
                {
                    sits[i - 1]++;
                }
            }
            if(sameChar)
            {
                res += *(sits[size - 1]);
                cout << res << endl;
                sits[size - 1]++;
                resLen++;
            }
        }
        return res;
    }
};

