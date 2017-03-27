class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 1 || primes.size() <= 0)
        	return n;
        int sizePrimes = primes.size();
        std::vector<int> superUglyNums(n);
        std::vector<int> indexPrimes(sizePrimes,0);
        superUglyNums[0] = 1;
        for(int i = 1;i < n;i++)
        {
        	int min = INT_MAX;
        	for(int index = 0;index < sizePrimes;index++)
        	{
        		if(min > primes[index] * superUglyNums[indexPrimes[index]])
        		{
        			min = primes[index] * superUglyNums[indexPrimes[index]];
        		}
        	}
        	superUglyNums[i] = min;
        	cout << min << endl;
        	for(int index = 0;index < sizePrimes;index++)
        	{
        		if(min >= superUglyNums[indexPrimes[index]] * primes[index] )
        			indexPrimes[index]++;
        	}
        }
        return superUglyNums[n - 1];
    }
};
