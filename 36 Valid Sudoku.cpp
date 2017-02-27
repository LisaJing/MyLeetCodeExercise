class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char ch;
        for(int i = 0;i < 9;i++)
        {
            vector<bool> isUsedRow(9,false);
            for(int j = 0;j < 9;j++)  //检查行内有没有元素重复
            {
                ch = board[i][j];
                if(checkIfDup(ch,isUsedRow)) //重复出现
                    return false;
            }
            
            vector<bool> isUsedColumn(9,false);
            for(int j = 0;j < 9;j++)  //检查列内有没有元素重复
            {
                ch = board[j][i];
                if(checkIfDup(ch,isUsedColumn)) //重复出现
                    return false;
            }
        }
        
        for(int no = 0;no < 3;no++ )
        {
            for(int times = 0; times < 3;times++)
            {
                vector<bool> isUsedGrid(9,false);
                for(int i = no * 3;i < 3 * (no + 1); i++)
                {
                    for(int j = times * 3;j < (times + 1) * 3;j++)
                    {
                        ch = board[i][j];
                        if(checkIfDup(ch,isUsedGrid))
                        {
                            return false;
                        }
                    }
                }
            }        
        }
        return true;
    }
    
    bool checkIfDup(char ch,vector<bool> &isUsed)
    {
        if(ch == '.')
            return false;
        int curIndex = ch - '1';
        if(isUsed[curIndex])
            return true;
        else
        {
            isUsed[curIndex] = true;
            return false;
        }
    }
};
