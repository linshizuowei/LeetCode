/*--There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity should 
be O(log (m+n)).
--*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums1 = {2,4,6,7,8,33};
	vector<int> nums2 = {5,6,8,45,76,77};
	
	auto iter1 = nums1.begin();
	auto iter2 = nums2.begin();
	
	int m = nums1.size();
	int n = nums2.size();
	int M1 = 0,M2 = 0;
		
	int cnt = 0;
	int num = 0;
	vector<int> tmp1;
	vector<int> tmp2;
	
	if ( m%2 == 0)
		M1 = (nums1[m%2] + nums1[m%2+1])/2.0;
	else 
		M1 = nums1[m%2+1]/1.0;
	
	if ( n%2 == 0)
		M2 = (nums2[n%2] + nums2[n%2+1])/2.0;
	else 
		M2 = nums2[n%2+1]/1.0;
	
	if ( M1 < M2 ){
		
	}

}
