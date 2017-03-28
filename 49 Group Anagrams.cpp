class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
    	std::vector<std::vector<string> > res;
    	int size = strs.size();
    	if(size <= 0)
    		return res;
    	unordered_map<string,vector<string> > sortStringMap;
    	for(int i = 0;i < size;i++)
    	{
    		string stmp(strs[i]);
    		sort(stmp.begin(),stmp.end());
    		unordered_map<string,vector<string> >::iterator uit = sortStringMap.find(stmp);
    		if(uit != sortStringMap.end())
    		{
    			(uit -> second).push_back(strs[i]);
    		}
    		else
    		{
    			sortStringMap[stmp].push_back(strs[i]);
    		}
    	}
    	for(unordered_map<string,vector<string> >::iterator uit= sortStringMap.begin();uit != sortStringMap.end();uit++)
    	{
    		std::vector<string> vTmp;
    		for(std::vector<string>::iterator vit = (uit -> second).begin(); vit != (uit -> second).end();vit++)
    		{
    			vTmp.push_back(*vit);
    		}
    		res.push_back(vTmp);
    	}
    	return res;   
    }
};
