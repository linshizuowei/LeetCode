#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = {0,0,1,2,2,2,3,3,4};
	int target = 2;
	vector<int> pos;
	
	int m = nums.size() / 2;
	int ld = 0;
	int rd = nums.size();
	
//	while ( nums[m] != target ){
//		while ( nums[m] > target && ld < rd){
//			rd = m;
//			m = (ld + rd)/2;
//		}
//		while ( nums[m] < target && ld < rd){
//			ld = m+1;
//			m = (m+1+rd)/2;
//		}
//		if ( ld >= rd )
//			break;
//	}
//	if (nums[m] != target){
//		pos.push_back(-1);
//		pos.push_back(-1);
//		//return pos;
//	}
	
	int lm = 0;
	int rm = 0;
	
	while ( ld < m ){
		lm = (ld + m)/2;
		if ( nums[lm] < target ){
			ld = lm+1;
		}
		else {
			m = lm;
		}
	}
	pos.push_back(ld);
	
	while ( rd > m+1 ){
		rm = (m+1+rd)/2;
		if ( nums[rm]>target ){
			rd = rm;
		}
		else {
			m = rm;
		}
	}
	pos.push_back(rd-1);
	
	cout << pos[0] <<' '<< pos[1] << endl;
}
