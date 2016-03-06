#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generatefunc(int left,int right,string s);

vector<string> v;

int main()
{
	int left = 3;
	int right = 3;
	string s;
	
	generatefunc(3,3,"");
	
	for (auto c : v)
		cout << c << endl;

//	cout << v[0];
}

void generatefunc(int left,int right,string s)
{
	if ( left > right ) return;
	
	if ( left > 0 )
		generatefunc(left-1,right,s+"(");
	
	if ( right > 0 )
		generatefunc(left,right-1,s+")");
	
	if ( left == 0 && right == 0 ){
	
		v.push_back(s);
		return;
	}
}
