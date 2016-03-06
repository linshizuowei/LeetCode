#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& i,int& j);

int main()
{
	vector<int> nums = {3,2,1};
	int s = 0;
	
	for ( s=nums.size()-1;s > 0;s--){
		if ( nums[s] > nums[s-1] )
			break;
	}
	
	int pre = s-1;
	int j = nums.size()-1;
	int tail = j;
	
	if ( s != 0 ){
		while ( nums[j] <= nums[pre] )
			j--;
		swap(nums[j],nums[pre]);
	}
	
	while ( tail > s ){
		swap ( nums[tail--],nums[s++] );
	}
	
	for (auto k : nums){
		cout << k <<' ';
	}
}

void swap(int& i,int& j){
	int temp = 0;
	temp = i;
	i = j;
	j = temp;
}
