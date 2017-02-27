#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size(); 
        if(size <= 0)
            return 0;
        unordered_map<int,int> numLoc;
        vector<int> findLen(size,1); //记录当前位置可以查到的最长序列，避免重复查找

        for(int i = 0;i < size;i++)
        {
            numLoc[nums[i]] = i;
        }
        
        int longestLen = 1;
        
        for(int i = 0;i < size;i++)
        {
            int curNum = nums[i];  //当前的数字
            int curLoc = i;    //当前数字的位置
            int len = 1;     //当前长度
            
            if(findLen[i] > 1)  //避免不必要的查找
                continue;
            
            int nextNum =  curNum + 1;   //下一个数字
            while( (numLoc.find(nextNum) != numLoc.end()) )   //查询下一个紧接着的数字
            {
                int nextLoc = numLoc.find(nextNum) -> second;  //下一个数字的位置
                if(findLen[nextLoc] > 1)  //从下个数字开始的连续序列
                {
                    findLen[curLoc] = len + findLen[nextLoc];
                    len = findLen[curLoc];
                    break;
                }
                else
                {
                    findLen[curLoc] =len + getLocLen(nums,findLen,numLoc,nextNum,nextLoc);
                    len = findLen[curLoc];
                    break;
                }
                
            }
            if(len > longestLen)
            {
                longestLen = len;
            }
        }
        return longestLen;
    }
    
    int getLocLen(vector<int>& nums,vector<int>& findLen,unordered_map<int,int>& numLoc,int curNum, int curLoc)
    {
    	
        int len = 1;
        int nextNum = curNum + 1;
        if(numLoc.find(nextNum) == numLoc.end() )
        {
       
            return findLen[curLoc];
        }
        else
        {
            int nextLoc = numLoc.find(nextNum) -> second;
            findLen[curLoc] = 1 + getLocLen(nums,findLen,numLoc,nextNum,nextLoc);
            return findLen[curLoc];
        }
        
    }
     
    
};

