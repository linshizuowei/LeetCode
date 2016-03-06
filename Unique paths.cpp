#include <iostream>
#include <vector>

using namespace std;

int path(int r,int c,int cnt,vector<vector<int>>& grid)
{
	if (grid[r][c] == 1)
		return cnt;
		
	if ( r == 0 && c == 0 )
		cnt++;
		
	if ( r > 0 ){
		cnt = path(r-1,c,cnt,grid);
	}
	if ( c > 0 ){
		cnt = path(r,c-1,cnt,grid);
	}
	
	return cnt;
}

int main()
{
	vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
	int m;
	int n;
	int cnt = 0;
	
	m = obstacleGrid.size();
	n = obstacleGrid[0].size();
	
	cnt = path(m-1,n-1,cnt,obstacleGrid);
	return cnt;
}


