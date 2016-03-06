#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	
	if (height.size() < 3)
		return 0;
	
	int l = 0;
	int r = height.size()-1;
	int lblock = height[l];
	int rblock = height[r];
	int grid = 0;
	int sum = 0;
	int i = 1;
	int j = height.size()-2;
	int max = 0;
	int pos = 0;
	
	for (int k=0;k<height.size();k++){
		if ( height[k] > max ){
			pos = k;
			max = height[k];
		}
	}
	

	while ( i <= pos ){
		if ( height[i] < height[l] ){
			lblock += height[i];
			i++;
		}
		else {
			grid = height[l] * (i-l) - lblock;
			sum += grid;
			
			l = i++;
			lblock = height[l];
			grid = 0;
		}
	}
	
	while ( j >= pos ){
		if ( height[j] < height[r] ){
			rblock += height[j];
			j--;
		}
		else {
			grid = height[r] * (r-j) - rblock;
			sum += grid;
			
			r = j--;
			rblock = height[r];
			grid = 0;

		}
	}
	
	
	return sum;
}
