class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 0)
        	return 0;
        int minPoint = prices[0];
        int curProfit = 0;
        int maxProfit = 0;
        int maxPoint = prices[0];
        for(int i = 1;i < size;i++)
        {
        	if(prices[i] < minPoint)
        	{
        		minPoint = prices[i];
        		maxPoint = prices[i];
        	}
        	else if(prices[i] > maxPoint)
        	{
        		maxPoint = prices[i];
        	}
        	curProfit = maxPoint - minPoint;
        	if(curProfit > maxProfit)
        		maxProfit = curProfit;
        }
        return maxProfit;
    }
};
