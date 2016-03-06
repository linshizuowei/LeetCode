#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> matrix = {
									 { 1, 2, 3,3 },
									 { 4, 5, 6,6 },
									 { 7, 8, 9,9 },
									 { 0, 0, 0,0 }
											
												};

	vector<int> spiral;
	int s = 1;
	if (matrix.size())
		s = 1;
	else 
		return spiral;
		
	int i = 0;
	int j = 0;
	int vs = matrix[0].size();
	int ms = matrix.size();
	
	while (1){
		if ( s == 1 )
			s = 0;
		else 
			//break;
			return spiral;
		for ( ;j < vs-i;++j ){
			s = 1;
			spiral.push_back(matrix[i][j]);
		}
		i++;
		j--;
		
		if ( s == 1 )
			s = 0;
		else 
			//break;
			return spiral;
		int r = i;
		for ( ;i <= ms-r;++i){
			s = 1;
			spiral.push_back(matrix[i][j]);
		}
		i--;
		j--;
		
		if ( s == 1 )
			s = 0;
		else 
			//break;
			return spiral;
		for ( ;j>=ms-1-i;--j ){
			s = 1;
			spiral.push_back(matrix[i][j]);
		}
		i--;
		j++;
		
		if ( s == 1 )
			s = 0;
		else 
			//break;
			return spiral;
		for ( ;i > j;--i ){
			s = 1;
			spiral.push_back(matrix[i][j]);
		}
		j++;
		i++;
	}
	
	for (auto i : spiral)
		cout << i <<' ';
}
