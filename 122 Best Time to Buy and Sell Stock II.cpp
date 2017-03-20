class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 0)
        	return 0;
        int minPoint = prices[0];
        int maxPoint = prices[0];
        int curProfit = 0;
        int maxProfit = 0;
        for(int i = 1;i < size;i++)
        {
        	if(prices[i] < maxPoint) 
        	{
        		curProfit = maxPoint - minPoint;
        		if(curProfit > 0)
        		{
        			maxProfit += curProfit;
        		}
        		minPoint = prices[i];
        		maxPoint = prices[i];
        	}
        	else
        	{
        		maxPoint = prices[i];
        		if(i == size - 1)
        		{
        			curProfit = maxPoint - minPoint;
        			if(curProfit > 0)
        			{
        				maxProfit += curProfit;
        			}	
        		}
        	}
        }
        return maxProfit;
    }
};
