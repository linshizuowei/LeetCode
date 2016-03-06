#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> res;


int check(int r,int c,vector<string> m,int n)
{
	
	for (int i=0;i<r;++i){
		if ( m[i][c] == 'Q' )
			return 0;
	}
	
	for (int j=0;j<c;++j){
		if ( m[r][j] == 'Q')
			return 0;
	}
	
	for (int i=r,j=c;i>=0 && j>=0;--i,--j){
		if (m[i][j] == 'Q')
			return 0;
	}
	
	for (int i=r,j=c;i>=0 && j<m.size();--i,++j){
		if ( m[i][j] == 'Q')
			return 0;
	}
	
	return 1;
}


void queen(int n,int r,vector<string> m)
{
	
	if ( r > n-1 ){
		res.push_back(m);
		//cout << "here" << endl;
		return;
	}
	for ( int i=0;i<n;++i ){
		
		
		if ( check(r,i,m,n) ){
			
			m[r][i] = 'Q';
		//	cout << m[r][i] << endl;
			queen(n,r+1,m);
			m[r][i] = '.';
		//	cout << m[r][i] << endl;
		}
	}
}



int main()
{
	int n = 9; 
	
	vector<string> m(n,"");
	
	for ( int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			m[i].push_back('.');
		}
	}
	
//	for ( auto i : m){
//		for (auto j:i)
//			cout << j <<' ';
//		cout << endl;
//	}
	
	queen(n,0,m);
	
	
	for (auto i : res){
		for (auto j : i){	
			cout << j << endl;
			
		}
		cout << endl;
	}
	cout << "res.size:" << res.size() <<endl;
	//cout << c <<endl;
}
