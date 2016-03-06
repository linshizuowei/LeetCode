#include <iostream>
#include <vector>

using namespace std;

//void permute(vector<int> nums,int x);

vector<vector<int>> res;


void permute(vector<int> nums,vector<int> tmp,vector<bool> mark,int size)
{
	if ( tmp.size() == nums.size() ){
		res.push_back(tmp);
		return;
	}
	
	for (int i=0;i<size;++i){
		if (mark[i] == true)
			continue;
		tmp.push_back(nums[i]);
		mark[i] = true;
		permute(nums,tmp,mark,size);
		tmp.pop_back();
		mark[i] = false;
	}
}


int main()
{
	vector<int> nums = {1,2,3};
	vector<int> tmp;
	vector<bool> mark(nums.size(),false);
	int size = nums.size();
	
	permute(nums,tmp,mark,size);
	
	for (int i=0;i<res.size();i++){
		for (auto j : res[i])
			cout << j << ' ';
		cout <<endl;
	}
}


