#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	vector<int> L = {1};
	int u2=0,u3=0,u5=0;
	int v=0,v2=0,v3=0,v5=0;
	
	while ( L.size() < n ){
		v2 = L[u2]*2;
		v3 = L[u3]*3;
		v5 = L[u5]*5;
		
		v = v2<v3? v2:v3;
		v = v<v5? v:v5;
		
		if ( v == v2 )
			++u2;
		if ( v == v3 )
			++u3;
		if ( v == v5 )
			++u5;
		L.push_back(v);
	}
	
	cout << L.back();
	return 0;
}
