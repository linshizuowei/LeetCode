#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add(vector<int> candidate,int target,int sum,int i,vector<int> subset);

vector<vector<int>> set;

int main()
{
	vector<int> candidate = {2,6,5,7,1,10,1};
	int target = 8;
	int sum = 0;
	vector<int> subset;
	
	for (int i=candidate.size()-1;i>=0;--i){
		add(candidate,target,sum,i,subset);
	}
	
	for (auto i : set){
		for (auto j : i){
			cout << j <<' ';
		}
		cout << endl;
	}
}

void add(vector<int> candidate,int target,int sum,int i,vector<int> subset)
{
	sum += candidate[i];
	subset.push_back(candidate[i]);
	
	while ( sum < target && i >= 0 ){
		
		add(candidate,target,sum,--i,subset);
	}
	
	if ( sum > target ){
		return;
	}
	
	if ( sum == target) {
		sort(subset.begin(),subset.end());
		for (auto j : set){
			if (j == subset)
				return;
		}
		
		set.push_back(subset);
		return;
	}
	
//	while ( i-- > 0 ){
//		add(candidate,target,sum,i,subset);
//	}
	
}
