#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = {1,2};
	
	int sum = 0;
	int cnt = 0;
	int max = 0;
	for (int i=0;i<nums.size();i++){
		if( nums[i] > 0){
			nums[nums[i]-1] = -nums[nums[i]-1];
		}
	}
	
	for ( int i=0;i<nums.size();i++){
		if ( nums[i] > 0)
			return i+1;
	}
	
}
