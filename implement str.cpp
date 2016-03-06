#include <iostream>
#include <string>

using namespace std;

int main()
{
	string haystack = "mississippi";
	string needle = "issip";
	
	int i,j,k;
	int s;
	
	for (i=0;i<haystack.size();++i){
		k = i;
		s = i;
		for (j=0;j<needle.size() && k<haystack.size();j++){
			if ( haystack[k] == needle[j] ){
				++k;
			}
			else {
				//i = k;
				break;
			}
		}
		
		if ( j < needle.size() && k == haystack.size() )
			return -1;
		if ( j == needle.size() )
			return s;
	}
	cout << -1 << endl;

//	return -1;
}
