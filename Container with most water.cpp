/*--Given n non-negative integers a1, a2, ..., an, where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms 
a container, such that the container contains the most water.

Note: You may not slant the container.
--*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> height = {2,10,9,5,6,12,3,7,1,16};
	int water = 0;
	int i = 0;
	int j = height.size()-1;
	int h;
	
	while ( i < j ){
		h = min(height[i],height[j]);
		water = max(water,(j-i)*h);
		
		while (height[i] <= h && i<j) ++i;
		while (height[j] <= h && i<j) --j;
	}
	
	cout << water << endl;
}
