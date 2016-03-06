#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> matrix = { {1,2,3,3,2},
							   {4,5,6,6,2},
							   {7,8,9,9,2},
							   {0,0,0,0,2},
							   {1,1,1,1,2} };
							      
	vector<vector<int>> a;
	
	int k = matrix.size();
	int m = k-1;
	int tmp = 0;
	for (int j=0;j<k/2;++j){
		
		for (int i=j;i<(j+k-2*j-1);++i){
			tmp = matrix[j][i];
			matrix[j][i] = matrix[m-i][j];
			matrix[m-i][j] = matrix[m-j][m-i];
			matrix[m-j][m-i] = matrix[i][m-j];
			matrix[i][m-j] = tmp;
		}
	}
	
	for (auto i : matrix){
		for (auto j : i)
			cout << j <<' ';
		cout << endl;
	}				
}
