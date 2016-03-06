#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums = {0};
	int sum=0;
	int n = nums[0];
	
	if (find(nums.begin(),nums.end(),0 ) == nums.end())
		cout << 0 <<endl;
	
	auto iter = nums.begin();
	while ( iter != nums.end()){
		if ( *iter > n )
			n = *iter;
		++iter;
	}
	
	iter = nums.begin();
	while ( iter != nums.end()){
		sum += *iter;
		++iter;
	}
	
	
	if ( n*(n+1)/2 - sum == 0)
		cout << n+1 << endl;
	cout << n*(n+1)/2 - sum;
	return 0;
}
