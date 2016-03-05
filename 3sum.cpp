#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> set;
	
	int k = 0;
	
	if ( nums.size() < 3 )
		return {};
	sort(nums.begin(),nums.end());
	
	while ( k < nums.size() && nums[k] <= 0)
	{
		int i = k+1;
		int j = nums.size()-1;
		
		while ( i<j )
		{
			int twosum = nums[i] + nums[j];
			
			if ( nums[k] + twosum < 0 )
			{
				++i;
				while (nums[i] == nums[i-1]) ++i;
				
			}
			else if ( nums[k] + twosum > 0 )
			{
				--j;
				while (nums[j] == nums[j+1]) --j;
			}
			else 
			{
				set.push_back({nums[k],nums[i],nums[j]});
				++i;
				while (nums[i] == nums[i-1]) ++i;
				--j;
				while (nums[j] == nums[j+1]) --j;
			}
		}
		
		k++;
		while (nums[k] == nums[k-1]) k++;
	}
	
	auto iter = set.begin();
	while ( iter != set.end())
	{
		for ( auto &i : *iter )
			cout << i <<" ";
		cout << endl;
		iter++;
	}
}
