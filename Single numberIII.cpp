#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int main()
{
	vector<int> result;
	vector<int> nums = {1,1,2,2,3,5,3,7};
	
	int XOR = accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
	
	
	int index = 0;
	while ((XOR & 1) == 0 ){
		XOR >>= 1;
	
		++index;
	}
	
	
	vector<int> nums1,nums2;
	auto iter = nums.begin();
	while (iter != nums.end()){
		if ( (*iter & (1 << index)) == 0 ){
			nums1.push_back(*iter);
			++iter;
		}else {
			nums2.push_back(*iter);
			++iter;
		}
	}
	
	result.push_back(accumulate(nums1.begin(),nums1.end(),0,bit_xor<int>()));
	result.push_back(accumulate(nums2.begin(),nums2.end(),0,bit_xor<int>()));
	
	cout << result[0] << endl << result[1];
	return 0;
}
