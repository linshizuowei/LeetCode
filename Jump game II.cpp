#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = {4,1,1,3,1,1,1};
	
	int i = 0;
	int s = 0;
	int b = i + nums[i];
	int pos = 0;
	int cnt = 0;
	
	
	while ( b < nums.size()-1 ){
		for (i=s;i<=s+nums[s];++i){
			if ( nums[i]+i > b ){
				b = nums[i]+i;
				pos = i;
			}
		}
		s = pos;
		cnt++;
	}
	return ++cnt;
}
