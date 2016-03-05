/* --Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers. You may 
assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
--*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<int> nums = {-1,1,1,-4};
	vector<vector<int>> set;
	int target = 1;
	int closest;
	
	int k = 0;
	
	if ( nums.size() < 3 )
		return {};
		
	sort(nums.begin(),nums.end());
	int Lclosest = nums[0] + nums[1] + nums[2];
	int Rclosest = nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3];
	int sigal = 0;
	
	while ( k < nums.size() )
	{
		int i = k+1;
		int j = nums.size()-1;
		
		while ( i<j )
		{
			int threesum = nums[i] + nums[j] + nums[k];
			
			if ( threesum < target )
			{
				if ( threesum > Lclosest )
				{
					Lclosest = threesum;
				}
				++i;
				while (nums[i] == nums[i-1]) ++i;
				
			}
			else if ( threesum > target )
			{
				if ( threesum < Rclosest )
				{
					Rclosest = threesum;
				}
				--j;
				while (nums[j] == nums[j+1]) --j;
			}
			else 
			{
//				set.push_back({nums[k],nums[i],nums[j]});
//				++i;
//				while (nums[i] == nums[i-1]) ++i;
//				--j;
//				while (nums[j] == nums[j+1]) --j;
				
				closest = threesum;
				sigal = 1;
				break;
			}
		}
		
		if ( sigal == 1 ) break;
		k++;
		while (nums[k] == nums[k-1]) k++;
	}
	
	if ( sigal == 0 ){
		if ( 1-Lclosest <= Rclosest-1 )
			closest = Lclosest;
		else 
			closest = Rclosest;
	}
	cout << closest <<endl;
}
