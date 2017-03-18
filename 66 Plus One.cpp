class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
  		std::vector<int> res;
  		bool add_one = true;
  		std::vector<int>::iterator vit = digits.end() - 1;
  		int curNum = 0;
  		while(vit != digits.begin() - 1 || add_one)
  		{
  			if(add_one)
  			{
  				int curVit = ( (vit != digits.begin() - 1) ? *vit : 0);
  				curNum = (curVit + 1) % 10;
  				add_one = (curVit + 1) / 10;
  			}
  			else
  			{
  				int curVit = ( (vit != digits.begin() - 1) ? *vit : 0);
  				curNum = (curVit) % 10;
  				add_one = (curVit) / 10; 
  			}
  			res.push_back(curNum);
  			if(vit != digits.begin() - 1)
  				vit--;
  		}
  		reverse(res.begin(),res.end());
  		return res;      
    }
};