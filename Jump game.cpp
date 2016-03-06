#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = {3,5,2,0,1,0};//{3,2,1,0,4}; //{2,3,1,1,4};
	int index = 0;
	int jump = 0;
	int rpos = 0;
	
	while ( index+nums[index] < nums.size()-1 ){
		jump = index + nums[index];
		rpos = jump;
		
		while ( nums[jump] == 0 || jump+nums[jump] <= rpos ){
			jump--;
			if ( jump < 0 )
				return false;
		}
		
		index = jump;
		
	}
	return true;
}
