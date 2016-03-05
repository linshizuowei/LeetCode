#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add(vector<int> candidate,int target,int sum,int i,vector<int> subset);

vector<vector<int>> set;

int main()
{
	vector<int> candidate = {2,6,5,7,4};
	int target = 16;
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
	
	if ( sum < target ){
		
		add(candidate,target,sum,i,subset);
	}
	else if ( sum > target ){
		return;
	}
	else {
		sort(subset.begin(),subset.end());
		set.push_back(subset);
		return;
	}
	
	while ( i-- > 0 ){
		add(candidate,target,sum,i,subset);
	}
	
}
