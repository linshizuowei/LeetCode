#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums = {-3,1,0,-1,0,-2,2,6,3};
	int target = 0;
	vector<vector<int>> set;
	
	if (nums.size() < 4)
		return {};
	sort(nums.begin(),nums.end());
	
	int Lf = 0;
	int Rf = nums.size()-1;
	int Ls = Lf+1;
	int Rs = Rf-1;
	int sum = 0;
	
	while ( Rf - Lf >= 3 ){
//		Ls = Lf + 1;
//		Rs = Rf -1;
		
		sum = nums[Lf] + nums[Ls] + nums[Rs] + nums[Rf];
		
		if ( sum > target ){
			if ( Rf - Rs == 1 ){
				Rs--;
			}else if (nums[Rf]-nums[Rf-1] >= nums[Rs]-nums[Rs-1]){
				Rs--;
			}else {
				Rf--;
			}
			
			if ( Rs == Ls )
				Rs--;
				
		}else if ( sum < target ){
//			if ( Ls - Lf == 1 ){
//				Ls++;
//			}else if ( nums[Lf+1]-nums[Lf] >= nums[Ls+1]-nums[Ls] ){
//				Ls++;
//			}else {
//				Lf++;
//			}
			
			Ls++;
			if ( Ls == Rs )
				Ls++;
				
		}else {
			cout << nums[Lf]<< ' ' <<nums[Ls]<<' ' <<nums[Rs]<<' ' <<nums[Rf] <<endl;
			set.push_back({nums[Lf],nums[Ls],nums[Rs],nums[Rf]});
			if ( Rs - Ls > 2){
				Rs--;
				while (nums[Rs] == nums[Rs+1])
					Rs--;
				Ls++;
				while (nums[Ls] == nums[Ls-1])
					Ls++;
				if (Rs <= Ls){
					int dis = (int)pow((Lf-target),2) - (int)pow((Rf-target),2);
					if ( dis < 0 ){
						Rf--;
						Rs = Rf-1;
					}else if ( dis > 0){
						Lf++;
						Ls = Lf + 1;
					}else {
						Rf--;
						Rs = Rf-1;
						Lf++;
						Ls = Lf + 1;
					}
				}
			}else {
				int dis = (int)pow((Lf-target),2) - (int)pow((Rf-target),2);
				if ( dis < 0 ){
					Rf--;
					Rs = Rf-1;
				}else if ( dis > 0){
					Lf++;
					Ls = Lf + 1;
				}else {
					Rf--;
					Rs = Rf-1;
					Lf++;
					Ls = Lf + 1;
				}
			}
			
		}
		
		if ( Ls >= Rf ){
			Lf++;
			Ls = Lf + 1;
			Rf = nums.size()-1;
			Rs = Rf - 1;
		}
		if ( Rs <= Lf ) {
//			Rf--;
//			Rs = Rf - 1;
//			Ls = Lf + 1;
			Lf++;
			Ls = Lf + 1;
			Rf = nums.size()-1;
			Rs = Rf - 1;
		}
	}
	
	
}
